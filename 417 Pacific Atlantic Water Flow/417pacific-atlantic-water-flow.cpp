class Solution {
public:
    void dfs(vector<vector<int>> &vis,vector<vector<int>> heights,int n,int m,int row,int col){
        queue<pair<int,int>> q;
        vis[row][col]=1;
        q.push({row,col});
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        while(!q.empty()){
            int row1=q.front().first;
            int col1=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row1+delrow[i];
                int ncol=col1+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && 
                heights[nrow][ncol]>=heights[row1][col1]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }

        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> vis_pacific(n,vector<int>(m,0));
        vector<vector<int>> vis_atlantic(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            dfs(vis_pacific,heights,n,m,i,0);
            dfs(vis_atlantic,heights,n,m,i,m-1);
        }
        for(int i=0;i<m;i++){
            dfs(vis_pacific,heights,n,m,0,i);
            dfs(vis_atlantic,heights,n,m,n-1,i);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis_pacific[i][j]==1 && vis_atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans; 
    }
};