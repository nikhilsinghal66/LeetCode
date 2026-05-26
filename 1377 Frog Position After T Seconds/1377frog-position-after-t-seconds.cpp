class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> graph(n+1);
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        queue<pair<double,int>> q;
        //{prob,node};
        q.push({1.0,1});
        vector<int> vis(n+1,0);
        vis[1]=1;
        int time=0;
        while(!q.empty()){
            int sze=q.size();
            while(sze--){
                auto it=q.front();
                double prob=it.first;
                int node=it.second;
                q.pop();
                int count=0;
                for(auto it:graph[node]){
                    if(!vis[it]){
                        count++;
                    }
                }
                if(node==target){
                    if(time==t) return prob;
                    if(t-time>0 && count==0) return prob;
                    if(t-time>0 && count>0) return 0;
                }
                for(auto it:graph[node]){
                    if(!vis[it]){
                        q.push({prob/count,it});
                        vis[it]=1;
                    }
                }
            }
            time++;
            if(time>t) break;
        }
        return 0;
    }
};