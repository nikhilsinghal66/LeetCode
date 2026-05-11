class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int m=prerequisites.size();
        int n=numCourses;
        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adj[b].push_back(a);
        }
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            result.push_back(val);
            for(auto it:adj[val]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(result.size()==n){
            return result;
        }
        return {};
        
    }
};