class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        //{diff,{row,col}}...
        pq.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int new_diff=max(diff,abs(heights[row][col]-heights[nrow][ncol]));
                    if(new_diff<dist[nrow][ncol]){
                        pq.push({new_diff,{nrow,ncol}});
                        dist[nrow][ncol]=new_diff;
                    }
                }
            }
        }
        return dist[n-1][m-1];       
    }
};