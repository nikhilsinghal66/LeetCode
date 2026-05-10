class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        queue<pair<int,int>> q;
        // {index, jumps}
        q.push({0,0});
        vector<int> best(n, -1);
        best[0] = 0;
        int ans = -1;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int ind = it.first;
            int jumps = it.second;
            if(ind == n-1) {
                ans = max(ans, jumps);
            }
            for(int j = ind + 1; j < n; j++) {
                if(abs(nums[j] - nums[ind]) <= target) {
                    if(jumps + 1 > best[j]) {
                        best[j] = jumps + 1;
                        q.push({j, jumps + 1});
                    }
                }
            }
        }
        return ans;
    }
};