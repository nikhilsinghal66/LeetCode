class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>>&grid2,
    vector<pair<int,int>> &dummy,vector<int> &delrow,vector<int> &delcol){
        int n=grid2.size();
        int m=grid2[0].size();
        vis[row][col]=1;
        dummy.push_back({row,col});
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && 
            grid2[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid2,dummy,delrow,delcol);
            }
        }
    }
    bool dfs1(vector<pair<int,int>> &arr,vector<vector<int>>& grid1){
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(grid1[arr[i].first][arr[i].second]!=1){
                return false;
            }
        }
        return true;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        vector<vector<pair<int,int>>> map;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        //Putting in map...
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && !vis[i][j]){
                    vector<pair<int,int>> dummy;
                    dfs(i,j,vis,grid2,dummy,delrow,delcol);
                    map.push_back(dummy);
                }
            }
        }
        //lets extract and find sub Island...
        int cnt=0;
        vector<vector<int>> vis1(n,vector<int>(m,0));
        for(auto it:map){
            if(dfs1(it,grid1)==true){
                cnt++;
            }
        }
        return cnt;  
    }
};