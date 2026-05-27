class Solution {
public:
    int mod=1e9+7;
    int dfs(vector<vector<pair<int,int>>> &graph,int &count ,int node,int target,vector<int> &dp,vector<int> &dist){
        if(node==target){ 
            return 1;
        }
        if(dp[node]!=-1) return dp[node];
        long long ways=0;
        for(auto it:graph[node]){
            if(dist[node]>dist[it.first]){
                ways+=dfs(graph,count,it.first,target,dp,dist);
                ways%=mod;
            }
        }
        return dp[node]=ways;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        //lets make graph first...
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }
        //Lets do Dijsktra's algo... to find dist from n to x node ... 
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //{dist,node}...
        pq.push({0,n});
        dist[n]=0;
        while(!pq.empty()){
            auto it=pq.top();
            int dist1=it.first;
            int node=it.second;
            pq.pop();
            for(auto it:graph[node]){
                int v=it.first;
                int wt=it.second;
                if(dist1+wt <dist[v]){
                    dist[v]=dist1+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        int count=0;
        vector<int> dp(n+1,-1);
        return dfs(graph,count,1,n,dp,dist);
    }
};