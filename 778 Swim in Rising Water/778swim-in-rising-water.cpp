class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        //{dist,{row,col}};
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=grid[0][0];
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            int time=it.first;
            int row1=it.second.first;
            int col1=it.second.second;
            pq.pop();
            if(row1==n-1 && col1==m-1){
                return time;
            }
            for(int i=0;i<4;i++){
                int nrow=row1+delrow[i];
                int ncol=col1+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                    int max_time=max(time,grid[nrow][ncol]);
                    if(max_time<dist[nrow][ncol]){
                        dist[nrow][ncol]=max_time;
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};