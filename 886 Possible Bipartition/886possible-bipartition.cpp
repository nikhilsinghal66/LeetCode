class Solution {
public:
    bool dfs(vector<int> &color,int node,vector<vector<int>> &adj){
        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it]=1-color[node];
                if(dfs(color,it,adj)==false){
                    return false;
                }
            }
            else if(color[it]==color[node]){
                return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //lets make adjaceny list...
        vector<vector<int>> adj(n+1);
        for(int i=0;i<dislikes.size();i++){
            int a=dislikes[i][0];
            int b=dislikes[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        //check bipartite...
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(dfs(color,i,adj)==false){
                    return false;
                }
            }
        }
        return true; 
    }
};