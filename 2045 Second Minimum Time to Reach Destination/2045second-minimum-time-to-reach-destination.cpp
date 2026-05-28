class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n+1);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        //{time,node}...
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        vector<int> dist(n+1,INT_MAX);
        vector<int> second_dist(n+1,INT_MAX);
        while(!pq.empty()){
            auto it=pq.top();
            int t=it.first;
            int node=it.second;
            pq.pop();
            //checking red/green light...
            int new_t=t;
            if((t/change)%2==1){
                new_t=((t/change)+1)*change;
            }
            new_t+=time;
            for(auto it:graph[node]){
                int v=it;
                if(new_t < dist[v]){
                    second_dist[v]=dist[v];
                    dist[v]=new_t;
                    pq.push({new_t,v});
                }
                else if(new_t>dist[v] && new_t<second_dist[v]){
                    second_dist[v]=new_t;
                    pq.push({new_t,v});
                }
            }
        }
        return second_dist[n];
        
    }
};