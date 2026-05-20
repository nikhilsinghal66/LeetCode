class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> mpp(n);
        int m=roads.size();
        int mod=1e9+7;
        for(int i=0;i<m;i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int time=roads[i][2];
            mpp[u].push_back({v,time});
            mpp[v].push_back({u,time});
        }
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,
        greater<pair<long long,int>>> pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            long long dist1=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(dist1>dist[node]) continue;
            for(auto it: mpp[node]){
                int v=it.first;
                int time=it.second;
                if(dist1+time < dist[v] ){
                    dist[v]=dist1+time;
                    pq.push({dist[v],v});
                    ways[v]=ways[node];
                }
                else if(dist1+time==dist[v]){
                    ways[v]=(ways[v]+ways[node])%mod;
                }
            }
        }
        return (ways[n-1])%mod;
    }
};