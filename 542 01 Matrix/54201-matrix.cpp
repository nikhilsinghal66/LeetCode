class Solution {
public:
    // void bfs(int row,int col,vector<vector<int>> &maze,vector<vector<int>> vis){
    //     int n=maze.size();
    //     int m=maze[0].size();
    //     queue<pair<int,pair<int,int>>> q;
    //     q.push({0,{row,col}});
    //     vis[row][col]=1;
    //     vector<int> delrow={-1,0,1,0};
    //     vector<int> delcol={0,1,0,-1};
    //     while(!q.empty()){
    //         int dist=q.front().first;
    //         int row1=q.front().second.first;
    //         int col1=q.front().second.second;
    //         q.pop();
    //         if(maze[row1][col1]==0){
    //             maze[row][col]=dist;
    //             return;
    //         }
    //         for(int i=0;i<4;i++){
    //             int nrow=row1+delrow[i];
    //             int ncol=col1+delcol[i];
    //             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && maze[nrow][ncol]==1 
    //             && !vis[nrow][ncol]){
    //                 q.push({dist+1,{nrow,ncol}});
    //                 vis[nrow][ncol]=1;
    //             }
    //         }
    //     }
    // }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0 ){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        while(!q.empty()){
            int row1=q.front().first;
            int col1=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row1+delrow[i];
                int ncol=col1+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                && dist[nrow][ncol]==-1){
                    q.push({nrow,ncol});
                    dist[nrow][ncol]=dist[row1][col1]+1;
                }
            }
        }
        return dist;
    }
};