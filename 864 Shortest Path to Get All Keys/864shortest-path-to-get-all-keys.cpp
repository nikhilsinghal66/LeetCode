class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int st_row=-1;
        int st_col=-1;
        int total_keys=0;
        //starting and total_keys...
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='@'){
                    st_row=i;
                    st_col=j;
                }
                if(grid[i][j]>='a' && grid[i][j]<='f'){
                    total_keys+=1;
                }
            }
        }
        int total_mask=(1<<total_keys)-1;
        vector<vector<vector<int>>> vis(n,vector<vector<int>>(m,vector<int>(64,false)));
        queue<vector<int>> q;
        //row,col,mask,dist...
        q.push({st_row,st_col,0,0});
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        vis[st_row][st_col][0]=1;
        while(!q.empty()){
            auto it=q.front();
            int row1=it[0];
            int col1=it[1];
            int mask=it[2];
            int dist=it[3];
            q.pop();
            if(mask==total_mask) return dist;
            for(int i=0;i<4;i++){
                int nrow=row1+delrow[i];
                int ncol=col1+delcol[i];
                int new_mask=mask;
                if(nrow<0 || nrow>=n || ncol<0 || ncol>=m){
                    continue;
                }
                //Check wall condition...
                if(grid[nrow][ncol]=='#'){
                    continue;
                }
                //Do we have key for that lock...Check...
                if(grid[nrow][ncol]>='A' && grid[nrow][ncol]<='F'){
                    if(!(mask&(1<<(grid[nrow][ncol]-'A')))){
                        continue;
                    }

                }
                //If we found key...
                if(grid[nrow][ncol]>='a' && grid[nrow][ncol]<='f'){
                    new_mask|=(1<<(grid[nrow][ncol]-'a'));
                }
                //Check it is visited...
                if(!vis[nrow][ncol][mask]){
                    vis[nrow][ncol][mask]=1;
                    q.push({nrow,ncol,new_mask,dist+1});
                }
            }
        }
        return -1;  
    }
};