class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indegree(n,0);
        vector<vector<int>> graph(n);
        for(auto it:relations){
            int a=it[0]-1;
            int b=it[1]-1;
            indegree[b]++;
            graph[a].push_back(b);
        }
        queue<int> q;
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            dp[i]=time[i];
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int num=q.front();
            q.pop();
            for(auto it:graph[num]){
                dp[it]=max(dp[it],dp[num]+time[it]);
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};