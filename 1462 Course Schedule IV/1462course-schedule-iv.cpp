class Solution {
public:
    void topo(vector<int> &indegree, vector<vector<int>> &graph,int n,
    vector<unordered_set<int>> &pre){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int num=q.front();
            q.pop();
            for(auto it:graph[num]){
                pre[it].insert(num);
                for(auto it1:pre[num]){
                    pre[it].insert(it1);
                }
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites,
    vector<vector<int>>& queries) {
        //first do Topo sort...
        vector<vector<int>> graph(numCourses);
        vector<unordered_set<int>> pre(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto it:prerequisites){
            int a=it[0];
            int b=it[1];
            graph[a].push_back(b);
            indegree[b]++;
        }
        topo(indegree,graph,numCourses,pre);
        vector<bool> answer(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0];
            int b=queries[i][1];
            if(pre[b].count(a)){
                answer[i]=true;
            }
        }
        return answer;
    }
};