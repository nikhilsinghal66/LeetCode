class Solution {
public:
    void bfs(vector<vector<int>> &vis,vector<vector<char>> grid,int row,int col
    ,int n,int m){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=1;
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
                grid[nrow][ncol]=='1'){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        } 
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    bfs(vis,grid,i,j,n,m);
                }
            }
        }
        return cnt;     
    }
};