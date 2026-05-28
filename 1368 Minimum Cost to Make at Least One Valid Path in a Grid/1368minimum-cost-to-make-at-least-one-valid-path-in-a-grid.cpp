class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        //{cost,{row,col}}...
        pq.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        vector<int> delrow={0,0,1,-1};
        vector<int> delcol={1,-1,0,0};
        while(!pq.empty()){
            auto it=pq.top();
            int cost=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                int new_cost=cost;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    if(grid[row][col]!=i+1){
                        new_cost++;
                    }
                    if(new_cost<dist[nrow][ncol]){
                        pq.push({new_cost,{nrow,ncol}});
                        dist[nrow][ncol]=new_cost;
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};