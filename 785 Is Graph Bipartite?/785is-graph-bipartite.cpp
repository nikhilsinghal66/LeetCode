class Solution {
public:
    bool dfs(vector<int> &color,vector<vector<int>> &adj ,int node){
        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                if(dfs( color, adj,it)==false){
                    return false;
                }
            }
            else if(color[node]==color[it]){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(dfs(color,graph,i)==false){
                    return false;
                }
            }
        }
        return true;
    }
};