class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> graph(n);
        int m1=redEdges.size();
        for(int i=0;i<m1;i++){
            int a=redEdges[i][0];
            int b=redEdges[i][1];
            graph[a].push_back({b,0});
        }
        int m2=blueEdges.size();
        for(int i=0;i<m2;i++){
            int a=blueEdges[i][0];
            int b=blueEdges[i][1];
            graph[a].push_back({b,1});
        }
        vector<vector<int>> vis(n,vector<int>(2,0));
        queue<vector<int>> q;
        //node,dist,lastcolor
        q.push({0,0,-1});
        vector<int> answer(n,-1);
        while(!q.empty()){
            auto it=q.front();
            int node=it[0];
            int dist=it[1];
            int lastcolor=it[2];
            q.pop();
            if(answer[node]==-1){
                answer[node]=dist;
            }
            for(auto it:graph[node]){
                int new_node=it.first;
                int new_color=it.second;
                if(new_color!=lastcolor && !vis[new_node][new_color]){
                    q.push({new_node,dist+1,new_color});
                    vis[new_node][new_color]=1;
                }
            }
        }
        return answer;  
    }
};