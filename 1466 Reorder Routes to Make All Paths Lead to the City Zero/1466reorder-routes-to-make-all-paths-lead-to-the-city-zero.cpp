class Solution {
public:
    void dfs(set<pair<int,int>> &edges,vector<vector<int>> &graph,int &changes,
    vector<int> &vis,int node){
        vis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(edges.find({it,node})==edges.end()){
                    changes++;
                }
                dfs(edges,graph,changes,vis,it);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        set<pair<int,int>> edges;
        vector<vector<int>> graph(n);
        int m=connections.size();
        for(int i=0;i<m;i++){
            int a=connections[i][0];
            int b=connections[i][1];
            edges.insert({a,b});
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int changes=0;
        vector<int> vis(n,0);
        dfs(edges,graph,changes,vis,0);
        return changes;
    }
};