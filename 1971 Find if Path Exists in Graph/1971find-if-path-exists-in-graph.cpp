class Solution {
public:
    void dfs(int source , vector<vector<int>> &adj, vector<int> &vis){
        vis[source]=1;
        for(auto it:adj[source]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        int m=edges.size();
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(source,adj,vis);
        if(vis[destination]) return true;
        return false; 
    }
};