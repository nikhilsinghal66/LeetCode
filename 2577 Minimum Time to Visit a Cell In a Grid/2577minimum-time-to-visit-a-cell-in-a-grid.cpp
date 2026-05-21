class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if( n>1 && m>1 && grid[0][1]>1 && grid[1][0]>1){
            return -1;
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        //{counter,{row,col}};
        pq.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            int counter=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            if(row==n-1 && col==m-1){
                return counter;
            }
            if(counter>dist[row][col]) continue;
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                    int new_time=counter+1;
                    if(grid[nrow][ncol]>new_time){
                        int diff=grid[nrow][ncol]-new_time;
                        if(diff%2==0){
                            new_time=grid[nrow][ncol];
                        }
                        else{
                            new_time=grid[nrow][ncol]+1;
                        }
                    }
                    if(new_time<dist[nrow][ncol]){
                        pq.push({new_time,{nrow,ncol}});
                        dist[nrow][ncol]=new_time;
                    }
                }
            }
        }
        return -1;
    }
};