class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        //only find indegree==0.
        //make adjaceny list...
        vector<vector<int>> adj(n);
        int m=edges.size();
        vector<int> indegree(n);
        for(int i=0;i<m;i++){
            int b=edges[i][1];
            indegree[b]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                ans.push_back(i);
            }
        }
        return ans; 
    }
};