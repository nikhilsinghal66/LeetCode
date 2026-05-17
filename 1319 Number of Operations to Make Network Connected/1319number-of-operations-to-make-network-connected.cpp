class Disjointset{
public:
    vector<int> rank;
    vector<int> parent;
    Disjointset(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findUparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUparent(parent[node]);
    }
    void findUnion(int u,int v){
        int u_ulp=findUparent(u);
        int v_ulp=findUparent(v);
        if(u_ulp==v_ulp) return ;
        if(rank[u_ulp]<rank[v_ulp]){
            parent[u_ulp]=v_ulp;
        }
        else if(rank[u_ulp]>rank[v_ulp]){
            parent[v_ulp]=u_ulp;
        }
        else{
            parent[v_ulp]=u_ulp;
            rank[u_ulp]++;
        }
    }
};

class Solution {
public:
    void dfs(vector<vector<int>> &graph,vector<int> &vis,int node){
        vis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                dfs(graph,vis,it);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjointset dsu(n);
        vector<vector<int>> graph(n);
        int m=connections.size();
        int ans=0;
        for(int i=0;i<m;i++){
            int a=connections[i][0];
            int b=connections[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
            if(dsu.findUparent(a)==dsu.findUparent(b)){
                ans++;
            }
            else if(dsu.findUparent(a)!=dsu.findUparent(b)){
                dsu.findUnion(a,b);
            }
        }
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(graph,vis,i);
            }
        }
        if(ans>=count-1){
            return count-1;
        }
        else{
            return -1;
        }  
    }
};