class Solution {
public:
    int dfs(vector<vector<int>>& graph,vector<int> &color,int node){
        for(auto it:graph[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                if(dfs(graph,color,it)==false){
                    return false;
                }
            }
            else if(color[node]==color[it]){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(dfs(graph,color,i)==false){
                    return false;
                }
            }
        }
        return true;
    }
};