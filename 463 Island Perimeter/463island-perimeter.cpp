class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int row=-1;
        int col=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    row=i;
                    col=j;
                }
            }
        }
        q.push({row,col});
        vis[row][col]=1;
        int total=4;
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        while(!q.empty()){
            int row1=q.front().first;
            int col1=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row1+delrow[i];
                int ncol=col1+delcol[i];
                if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && grid[nrow][ncol]==1 &&
                !vis[nrow][ncol]){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                    total+=4;
                    for(int i=0;i<4;i++){
                        int nrow1=nrow+delrow[i];
                        int ncol1=ncol+delcol[i];
                        if(nrow1>=0 && nrow1<n && ncol1>=0 && ncol1<m && grid[nrow1][ncol1]==1
                        && vis[nrow1][ncol1]){
                            total-=2;
                        }
                    }
                }
            }

        }
        return total;  
    }
};