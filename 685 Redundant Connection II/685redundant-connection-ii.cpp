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
    bool UnionByRank(int u,int v){
        int u_ulp=findUPar(u);
        int v_ulp=findUPar(v);
        if(u_ulp==v_ulp) return false;
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
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        //find two parents...
        int n=edges.size();
        vector<int> parent(n+1,0);
        vector<int> cand1,cand2;
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(parent[v]!=0){
                cand1={parent[v],v};
                cand2={u,v};
                edges[i][1]=0;
            }
            else{
                parent[v]=u;
            }
        }
        //Find DSU...
        DisjoinSet dsu(n);
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(v==0) continue;
            //Have cycle ...
            if(!(dsu.UnionByRank(u,v))){
                //if not two parent case...
                if(cand1.empty()){
                    return {u,v};
                }
                //Cycle + two parent case...
                else{
                    return cand1;
                }
            }
        }
        //if not cycle ,only two parent...
        return cand2;
    }
};