class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        queue<pair<int,pair<int,pair<int,int>>>> q;
        q.push({k,{0,{0,0}}});
        vis[0][0]=k;
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        while(!q.empty()){
            int left=q.front().first;
            int dist=q.front().second.first;
            int row=q.front().second.second.first;
            int col=q.front().second.second.second;
            if(row==n-1 && col==m-1) return dist;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                    int newk=left-grid[nrow][ncol];
                    if(newk>=0 && vis[nrow][ncol]<newk){
                        q.push({newk,{dist+1,{nrow,ncol}}});
                        vis[nrow][ncol]=newk;
                    }
                }
            }
        }
        return -1;  
    }
};