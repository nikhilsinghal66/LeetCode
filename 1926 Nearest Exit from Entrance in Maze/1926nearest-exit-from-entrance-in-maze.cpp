class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //Dikjstra's algorithm...
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{entrance[0],entrance[1]}});
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[entrance[0]][entrance[1]]=1;
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        while(!q.empty()){
            int dist=q.front().first;
            int row1=q.front().second.first;
            int col1=q.front().second.second;
            q.pop();
            if((row1==0 || col1==0 || row1==n-1 || col1==m-1) && !(row1 == entrance[0] 
            && col1 == entrance[1])){
                return dist;
            }
            for(int i=0;i<4;i++){
                int nrow=row1+delrow[i];
                int ncol=col1+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && maze[nrow][ncol]=='.' 
                && !vis[nrow][ncol]){
                    q.push({dist+1,{nrow,ncol}});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return -1;
    }
};