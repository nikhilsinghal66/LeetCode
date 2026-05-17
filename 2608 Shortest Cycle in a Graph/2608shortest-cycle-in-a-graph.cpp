class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<m;i++){
            int a=edges[i][0];
            int b=edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int min_len=INT_MAX;
        for(int i=0;i<n;i++){
            queue<int> q;
            vector<int> vis(n,0);
            vector<int> dist(n,-1);
            vector<int> parent(n,-1);
            dist[i]=0;
            vis[i]=1;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto it:graph[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        dist[it]=dist[node]+1;
                        q.push(it);
                        parent[it]=node;
                    }
                    else if(parent[node]!=it){
                        min_len=min(min_len,dist[node]+dist[it]+1);
                    }
                }
            }
        }
        return min_len==INT_MAX ? -1:min_len;
    }
};