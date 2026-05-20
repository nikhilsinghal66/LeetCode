class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //bus_stop->buses...
        if(source==target) return 0;
        int n=routes.size();
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            for(auto it:routes[i]){
                mpp[it].push_back(i);
            }
        }
        queue<pair<int,int>> q;
        q.push({source,0});
        unordered_set<int> vis_bus;
        unordered_set<int> vis_bus_stand;
        //vis_bus.insert();
        vis_bus_stand.insert(source);
        while(!q.empty()){
            auto it=q.front();
            int bus=it.first;
            int dist=it.second;
            q.pop();
            if(bus==target) return dist;
            for(auto it1:mpp[bus]){
                if(vis_bus.count(it1)){
                    continue;
                }
                vis_bus.insert(it1);
                    for(auto it2:routes[it1]){
                        if(!vis_bus_stand.count(it2)){
                            q.push({it2,dist+1});
                            vis_bus_stand.insert(it2);
                        }
                    }
            }
        }
        return -1;
    }
};