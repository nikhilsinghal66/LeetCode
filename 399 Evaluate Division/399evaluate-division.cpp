class Solution {
public:
    double dfs(unordered_map<string,vector<pair<string,double>>> &adj,string &s1, 
    string s2,unordered_set<string> &vis){
        if(s1==s2) return 1;
        vis.insert(s1);
        for(auto it:adj[s1]){
            string str=it.first;
            double val1=it.second;
            if(!vis.count(str)){
                double ans=dfs(adj,str,s2,vis);
                if(ans!=-1){
                    return val1*ans;
                }
            }
        }
        return -1;
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<n;i++){
            string a=equations[i][0];
            string b=equations[i][1];
            double val=values[i];
            adj[a].push_back({b,val});
            adj[b].push_back({a,1.0/val});
        }
        //Traverse through each queries...
        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            unordered_set<string> vis;
            string str1=queries[i][0];
            string str2=queries[i][1];
            if(adj.find(str1)==adj.end() || adj.find(str2)==adj.end()){
                ans.push_back(-1.0);
                continue;
            }
            double value=dfs(adj,str1,str2,vis);
            ans.push_back(value);
        }
        return ans;
    }
};