class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+2);
        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans=-1;
        int result_count=-1;
        for(int i=0;i<adj.size();i++){
            int count=adj[i].size();
            if(count>result_count){
                result_count=count;
                ans=i;
            }
        }
        return ans;
    }
};