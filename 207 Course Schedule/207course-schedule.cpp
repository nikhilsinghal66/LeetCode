class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m=prerequisites.size();
        int n=numCourses;
        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adj[b].push_back(a);
        }
        queue<int> q;
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        set<int> st;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            st.insert(val);
            for(auto it:adj[val]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push({it});
                }
            }
        }
        if(st.size()==n){
            return true;
        }
        return false;

        
    }
};