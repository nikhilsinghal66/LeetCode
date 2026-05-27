class DisjointSet{
public:
    vector<int> parent;
    vector<int> rank;
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findUparent(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findUparent(parent[u]);
    }
    void findUnion(int u,int v){
        int u_ulp=findUparent(u);
        int v_ulp=findUparent(v);
        if(u_ulp==v_ulp) return;
        if(rank[u_ulp]>rank[v_ulp]){
            parent[v_ulp]=u_ulp;
        }
        else{
            parent[u_ulp]=v_ulp;
            rank[v_ulp]++;
        }
    }
};


class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        //Exploring ...
        //Sort the meethings with time...
        sort(meetings.begin(),meetings.end(),[](vector<int> &a ,vector<int> &b){
            return a[2]<b[2];
        });
        DisjointSet dsu(n);
        int i=0;
        int m=meetings.size();
        dsu.findUnion(0,firstPerson);
        while(i<m){
            set<int> st;
            int time=meetings[i][2];
            while(i<m && time==meetings[i][2]){
                int x=meetings[i][0];
                int y=meetings[i][1];
                dsu.findUnion(x,y);
                st.insert(x);
                st.insert(y);
                i++;
            }
            for(auto it:st){
                if(dsu.findUparent(it)!=dsu.findUparent(0)){
                    dsu.parent[it]=it;
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dsu.findUparent(i)==dsu.findUparent(0)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};