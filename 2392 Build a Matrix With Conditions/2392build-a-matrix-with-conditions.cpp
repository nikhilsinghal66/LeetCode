class Solution {
public:
    vector<int> topo(vector<vector<int>> graph,vector<int> indegree,int k){
        queue<int> q;
        for(int i=1;i<=k;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty()){
            int num=q.front();
            q.pop();
            result.push_back(num);
            for(auto it:graph[num]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return result;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
    vector<vector<int>>& colConditions) {
        vector<vector<int>> graph1(k+1);
        vector<vector<int>> graph2(k+1);
        int n=rowConditions.size();
        int m=colConditions.size();
        vector<int> indegreeR(k+1,0);
        vector<int> indegreeC(k+1,0);
        for(int i=0;i<n;i++){
            int a=rowConditions[i][0];
            int b=rowConditions[i][1];
            indegreeR[b]++;
            graph1[a].push_back(b);
        }
        for(int i=0;i<m;i++){
            int a=colConditions[i][0];
            int b=colConditions[i][1];
            indegreeC[b]++;
            graph2[a].push_back(b);
        }
        vector<int> topo1=topo(graph1,indegreeR,k);
        vector<int> topo2=topo(graph2,indegreeC,k);
        if(topo1.size()!=k) return {};
        if(topo2.size()!=k) return {};
        unordered_map<int,int> mppR;
        unordered_map<int,int> mppC;
        for(int i=0;i<k;i++){
            mppR[topo1[i]]=i;
        }
        for(int i=0;i<k;i++){
            mppC[topo2[i]]=i;
        }
        vector<vector<int>> ans(k,vector<int>(k,0));
        for(int i=1;i<=k;i++){
            ans[mppR[i]][mppC[i]]=i;
        }
        return ans;  
    }
};