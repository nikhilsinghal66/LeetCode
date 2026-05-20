class Solution {
public:
    int maxCandies(vector<int>& status,
                   vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        unordered_set<int> keySet;
        unordered_set<int> owned;
        unordered_set<int> visited;
        queue<int> q;
        for(auto it : initialBoxes) {
            owned.insert(it);
            q.push(it);
        }
        int total_candies = 0;
        while(!q.empty()) {
            int box = q.front();
            q.pop();
            // cannot open
            if(status[box] == 0 && !keySet.count(box)) {
                continue;
            }
            // already used
            if(visited.count(box)) {
                continue;
            }
            visited.insert(box);
            total_candies += candies[box];
            // get keys
            for(auto it : keys[box]) {
                keySet.insert(it);
                // only push if we own it
                if(owned.count(it)) {
                    q.push(it);
                }
            }
            // get contained boxes
            for(auto it : containedBoxes[box]) {
                owned.insert(it);
                q.push(it);
            }
        }
        return total_candies;
    }
};