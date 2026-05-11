class Solution {
public:
    vector<int> delrow={-1,0,1,0};
    vector<int> delcol={0,1,0,-1};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();
        priority_queue<vector<int>,vector<vector<int>> , greater<vector<int>>> pq;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    pq.push({heightMap[i][j],i,j});
                    vis[i][j]=1;
                }
            }
        }
        int water=0;
        while(!pq.empty()){
            auto it=pq.top();
            int height=it[0];
            int row1=it[1];
            int col1=it[2];
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row1+delrow[i];
                int ncol=col1+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    if(heightMap[nrow][ncol]<height){
                        water+=height-heightMap[nrow][ncol];
                    }
                    pq.push({max(heightMap[nrow][ncol],height),nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return water;
    }
};