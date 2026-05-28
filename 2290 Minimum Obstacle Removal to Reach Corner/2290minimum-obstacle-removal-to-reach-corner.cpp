class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        //{obstacle,{row,col}}...
        pq.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            int obst=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    int new_obst=obst+grid[nrow][ncol];
                    if(new_obst < dist[nrow][ncol]){
                        pq.push({new_obst,{nrow,ncol}});
                        dist[nrow][ncol]=new_obst;
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};