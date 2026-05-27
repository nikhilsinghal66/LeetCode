class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int final_mask=(1<<n)-1;
        vector<vector<int>> vis(n,vector<int>(1<<n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        //{dist,{mask,node}}...
        for(int i=0;i<n;i++){
            int mask=1<<i;
            pq.push({0,{mask,i}});
            vis[i][mask]=1;
        }
        while(!pq.empty()){
            auto it=pq.top();
            int dist=it.first;
            int mask=it.second.first;
            int node=it.second.second;
            pq.pop();
            if(final_mask==mask) return dist;
            int new_mask=mask;
            for(auto it1:graph[node]){
                new_mask=mask|(1<<it1);
                if(!vis[it1][new_mask]){
                    pq.push({dist+1,{new_mask,it1}});
                    vis[it1][new_mask]=1;
                }
            }
        }
        return -1;
    }
};