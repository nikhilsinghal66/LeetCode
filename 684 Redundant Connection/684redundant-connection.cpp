class DisjoinSet{
public: 
    vector<int> rank;
    vector<int> parent;
    DisjoinSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findUPar(parent[u]);
    }
    void findByRank(int u,int v){
        int u_ulp=findUPar(u);
        int v_ulp=findUPar(v);
        if(u_ulp==v_ulp) return;
        if(rank[u_ulp]>rank[v_ulp]){
            parent[v_ulp]=u_ulp;
        }
        else if(rank[u_ulp]<rank[v_ulp]){
            parent[u_ulp]=v_ulp;
        }
        else {
            parent[u_ulp]=v_ulp;
            rank[v_ulp]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjoinSet DSU(n);
        for(int i=0;i<n;i++){
            int a=edges[i][0];
            int b=edges[i][1];
            if(DSU.findUPar(a)!=DSU.findUPar(b)){
                DSU.findByRank(a,b);
            }
            else {
                return {a,b};
            }
        }
        return {};
    }
};