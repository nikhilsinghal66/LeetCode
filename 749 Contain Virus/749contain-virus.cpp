class Solution {
public:
    vector<int> delrow={-1,0,1,0};
    vector<int> delcol={0,1,0,-1};
    void dfs(vector<vector<int>>& isInfected,
    vector<pair<int,int>> &region,set<pair<int,int>> 
    &frontier,int &walls,vector<vector<int>> &vis,int row,
    int col){
        int n=isInfected.size();
        int m=isInfected[0].size();
        vis[row][col]=1;
        region.push_back({row,col});
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                //infected region
                if(isInfected[nrow][ncol]==1 && !vis[nrow][ncol]){
                    dfs(isInfected,region,frontier,walls,
                    vis,nrow,ncol);
                }
                //frontier cell
                else if(isInfected[nrow][ncol]==0){
                    walls++;
                    frontier.insert({nrow,ncol});
                }
            }
        }
    }

    int containVirus(vector<vector<int>>& isInfected) {
        int n=isInfected.size();
        int m=isInfected[0].size();
        int ans=0;
        while(true){
            vector<vector<pair<int,int>>> regions;
            vector<set<pair<int,int>>> frontiers;
            vector<int> wallsNeeded;
            vector<vector<int>> vis(n,vector<int>(m,0));
            //find all regions...
            //Infected , frontier, walls_needed...
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(isInfected[i][j]==1 && !vis[i][j]){
                        vector<pair<int,int>> region;
                        set<pair<int,int>> frontier;
                        int walls=0;
                        dfs(isInfected,region,frontier,
                        walls,vis,i,j);
                        regions.push_back(region);
                        frontiers.push_back(frontier);
                        wallsNeeded.push_back(walls);
                    }
                }
            }
            if(regions.empty()) break;
            int ind=0;
            for(int i=1;i<frontiers.size();i++){
                if(frontiers[i].size()>frontiers[ind].size()){
                    ind=i;
                }
            }

            if(frontiers[ind].empty()) break;
            ans+=wallsNeeded[ind];
            for(auto cell:regions[ind]){
                int row=cell.first;
                int col=cell.second;
                isInfected[row][col]=-1;
            }
            for(int i=0;i<regions.size();i++){
                if(i==ind) continue;
                for(auto cell:frontiers[i]){
                    int row=cell.first;
                    int col=cell.second;
                    isInfected[row][col]=1;
                }
            }
        }
        return ans;  
    }
};