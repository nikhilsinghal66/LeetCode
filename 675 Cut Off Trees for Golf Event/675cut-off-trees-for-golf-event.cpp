class Solution {
public:
    vector<int> delrow={-1,0,1,0};
    vector<int> delcol={0,1,0,-1};
    int bfs(int sr,int sc,int tr,int tc,int target ,vector<vector<int>>& forest ){
        int n=forest.size();
        int m=forest[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[sr][sc]=1;
        int steps=0;
        while(!q.empty()){
            int size1=q.size();
            while(size1--){
                int row1=q.front().first;
                int col1=q.front().second;
                q.pop();
                if(row1==tr && col1==tc){
                    return steps;
                }
                for(int i=0;i<4;i++){
                    int nrow=row1+delrow[i];
                    int ncol=col1+delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && 
                    forest[nrow][ncol]>0){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }


    int cutOffTree(vector<vector<int>>& forest) {
        int n=forest.size();
        int m=forest[0].size();
        //{target,row,col}...
        vector<vector<int>> value;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]>1){
                    value.push_back({forest[i][j],i,j});
                }
            }
        }
        int sr=0;
        int sc=0;
        sort(value.begin(),value.end());
        int result=0;
        for(auto it: value){
            int target=it[0];
            int tr=it[1];
            int tc=it[2];
            int dist=bfs(sr,sc,tr,tc,target,forest);
            if(dist==-1){
                return -1;
            }
            result+=dist;
            sr=tr;
            sc=tc;
        }
        return result;
    }
};