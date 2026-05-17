class Solution {
public:
    void dfs(int node,vector<int> &tin,vector<int> &low,vector<int> &vis,
    vector<vector<int>>&ans, vector<vector<int>>&graph,int &time,int parent){
        vis[node]=1;
        tin[node]=time;
        low[node]=time;
        time++;
        for(auto it:graph[node]){
            if(it==parent){
                continue;
            }
            if(!vis[it]){
                dfs(it,tin,low,vis,ans,graph,time,node);
                low[node]=min(low[node],low[it]);
                if(tin[node]<low[it]){
                    ans.push_back({node,it});
                }
            }
            else{
                low[node]=min(low[node],tin[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<m;i++){
            int a=connections[i][0];
            int b=connections[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<int> tin(n,0);
        vector<int> low(n,0);
        vector<int> vis(n,0);
        vector<vector<int>> ans;
        int time=0;
        dfs(0,tin,low,vis,ans,graph,time,-1);
        return ans;
    }
};