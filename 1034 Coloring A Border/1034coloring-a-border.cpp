class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n=grid.size();
        int m=grid[0].size();
        int value=grid[row][col];
        queue<pair<int,int>> q;
        q.push({row,col});
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[row][col]=1;
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        vector<pair<int,int>> borders;
        // grid[row][col]=color;
        while(!q.empty()){
            int row1=q.front().first;
            int col1=q.front().second;
            bool isborder=false;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row1+delrow[i];
                int ncol=col1+delcol[i];
                if(nrow<0 || ncol<0 || nrow>=n || ncol>=m){
                    isborder=true; 
                }
                else if(grid[nrow][ncol]!=value){
                    isborder=true;
                }
                else if (!vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
            if(isborder){
                borders.push_back({row1,col1});
            }
        }
        for(auto &it:borders){
            grid[it.first][it.second]=color;
        }
        return grid;  
    }
};