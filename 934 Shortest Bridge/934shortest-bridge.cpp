class Solution {
public:
//filling 2 in first island...
    void dfs(int row,int col,vector<vector<int>> &dummy,vector<vector<int>> &vis
    , vector<int> delrow,vector<int> delcol,int n,int m){
        vis[row][col]=1;
        dummy[row][col]=2;
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && 
            dummy[nrow][ncol]==1){
                dfs(nrow,ncol,dummy,vis,delrow,delcol,n,m);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dummy=grid;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        bool found=false;
        //First,fill first island with 2... (to distinguish)
        for(int i=0;i<n;i++){
            if(found){
                break;
            }
            for(int j=0;j<m;j++){
                if(dummy[i][j]==1){
                    dfs(i,j,dummy,vis,delrow,delcol,n,m);
                    found=true;
                    break;
                }
            }
        }
        //Find the shortest path with queue...
        //Putting every element of first island and 
        // then ,finding distance to second island...
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> vis1(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dummy[i][j]==1){
                    q.push({0,{i,j}});
                    vis1[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int dist=q.front().first;
            int row1=q.front().second.first;
            int col1=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row1+delrow[i];
                int ncol=col1+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis1[nrow][ncol]){
                    if(dummy[nrow][ncol]==2){
                        return dist;
                    }
                    if(dummy[nrow][ncol]==0){
                        vis1[nrow][ncol]=1;
                        q.push({dist+1,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;  
    }
};