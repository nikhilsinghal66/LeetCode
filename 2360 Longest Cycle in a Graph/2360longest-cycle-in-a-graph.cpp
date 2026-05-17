class Solution {
public:
    void dfs(vector<vector<int>> &graph,int &max_len,int len,vector<int> &vis,
    int node,int parent,vector<int> &path_vis,vector<int> &depth){
        vis[node]=1;
        path_vis[node]=1;
        depth[node]=len;
        for(auto it:graph[node]){
            if(it==-1){
                continue;
            }
            if(!vis[it]){
                dfs(graph,max_len,len+1,vis,it,node,path_vis,depth);
            }
            else if(path_vis[it]){
                int len_temp=len-depth[it]+1;
                max_len=max(max_len,len_temp);
            }
        }
        path_vis[node]=0;
    }

    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            int a=i;
            int b=edges[i];
            graph[a].push_back(b);
        }
        int max_len=-1;
        int len=0;
        vector<int> vis(n,0);
        vector<int> path_vis(n,0);
        vector<int> depth(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph,max_len,len,vis,i,-1,path_vis,depth);
            }
        }
        return max_len;
    }
};