class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> vis(n,vector<int> (m,0));
        bool haswater=false;
        bool hasland=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    haswater=true;
                }
                if(grid[i][j]==1){
                    hasland=true;
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        if(!haswater || !hasland){
            return -1;
        }
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        int dist1=INT_MIN;
        while(!q.empty()){
            int dist=q.front().first;
            int row1=q.front().second.first;
            int col1=q.front().second.second;
            q.pop();
            dist1=max(dist1,dist);
            for(int i=0;i<4;i++){
                int nrow=row1+delrow[i];
                int ncol=col1+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    q.push({dist+1,{nrow,ncol}});
                    vis[nrow][ncol]=1;
                }
            }

        }
        return dist1;
        
    }
};