class Solution {
public:
    int bfs(int row,int col ,vector<vector<int>> &vis, vector<vector<int>> &grid,
    vector<int> &delrow , vector<int> &delcol,int n,int m){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=1;
        int total=0;
        while(!q.empty()){
            int row1=q.front().first;
            int col1=q.front().second;
            total+=1;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row1+delrow[i];
                int ncol=col1+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] 
                && grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return total;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        int max_area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int area=bfs(i,j,vis,grid,delrow,delcol,n,m);
                    max_area=max(max_area,area);
                }
            }
        }
        return max_area;
    }
};