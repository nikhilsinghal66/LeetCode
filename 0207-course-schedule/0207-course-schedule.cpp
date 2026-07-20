class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Kahn's algo...
        //Indegree...
        vector<int> indegree(numCourses,0);
        vector<int> vis(numCourses,0);
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        for(auto it: prerequisites ){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                vis[i]=1;
            }
        }
        vector<int> ans;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                    indegree[it]--;
                    if(indegree[it]==0){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
        if(ans.size()!=numCourses){
            return false;
        }
        return true;
    }
};