class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
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
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    if(dist[row1][col1]+1  <dist[nrow][ncol]){
                        dist[nrow][ncol]=dist[row1][col1] +1;
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }

                }
            }
        }
        return dist; 
    }
};