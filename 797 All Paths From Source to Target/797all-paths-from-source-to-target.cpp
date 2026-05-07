class Solution {
public:
    void dfs(int node,vector<int> &temp,vector<vector<int>> &adj,vector<vector<int>> &ans,int n){
        temp.push_back(node);
        if(node==n-1){
            ans.push_back(temp);
            temp.pop_back();
            return;
        } 
        for(auto it:adj[node]){
            dfs(it,temp,adj,ans,n);    
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(0,temp,graph,ans,n);
        return ans;
    }
};