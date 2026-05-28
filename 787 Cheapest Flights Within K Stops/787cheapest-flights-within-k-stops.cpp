class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //Graph done ...
        vector<vector<pair<int,int>>> graph(n);
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            graph[u].push_back({v,wt});
        }
        //{flights,{price,node}}...
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,src}});
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        while(!pq.empty()){
            auto it=pq.top();
            int flight=it.first;
            int price=it.second.first;
            int node=it.second.second;
            pq.pop();
            for(auto it:graph[node]){
                int v=it.first;
                int wt=it.second;
                if(wt+price < dist[v] && flight<=k){
                    pq.push({flight+1,{wt+price,v}});
                    dist[v]=wt+price;
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};