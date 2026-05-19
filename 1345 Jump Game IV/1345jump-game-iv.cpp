class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++) {
            mpp[arr[i]].push_back(i);
        }

        queue<pair<int,int>> q;

        q.push({0,0});

        unordered_set<int> vis;

        vis.insert(0);

        while(!q.empty()) {

            auto it = q.front();

            int ind = it.first;
            int dist = it.second;

            q.pop();

            if(ind == n-1)
                return dist;

            // i + 1
            int new_ind = ind + 1;

            if(new_ind < n && !vis.count(new_ind)) {

                q.push({new_ind, dist+1});

                vis.insert(new_ind);
            }

            // i - 1
            int new_ind1 = ind - 1;

            if(new_ind1 >= 0 && !vis.count(new_ind1)) {

                q.push({new_ind1, dist+1});

                vis.insert(new_ind1);
            }

            // same values
            for(auto next : mpp[arr[ind]]) {

                if(!vis.count(next)) {

                    q.push({next, dist+1});

                    vis.insert(next);
                }
            }

            // optimization
            mpp[arr[ind]].clear();
        }

        return -1;
    }
};