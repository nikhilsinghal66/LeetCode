class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> graph(n);
        int m=edges.size();
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            graph[u].push_back({v,prob});
            graph[v].push_back({u,prob});
        }
        //{prob,node}...
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});
        vector<double> dist(n,INT_MIN);
        dist[start_node]=1.0;
        while(!pq.empty()){
            auto it=pq.top();
            double prob=it.first;
            int node=it.second;
            pq.pop();
            if(node==end_node) return prob;
            for(auto it:graph[node]){
                int v=it.first;
                double wt=it.second;
                if(wt*prob>dist[v]){
                    dist[v]=wt*prob;
                    pq.push({dist[v],v});
                }
            }
        }
        return 0;
        
    }
};