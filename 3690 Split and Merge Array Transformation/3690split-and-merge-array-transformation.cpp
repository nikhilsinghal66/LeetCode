class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        queue<pair<vector<int>, int>> q;  
        set<vector<int>> visited;         

        q.push({nums1, 0});
        visited.insert(nums1);

        while (!q.empty()) {
            auto [arr, steps] = q.front();
            q.pop();

            // Check if we reached nums2
            if (arr == nums2) return steps;

            // Try all subarray removals [L..R]
            for (int L = 0; L < n; L++) {
                for (int R = L; R < n; R++) {
                    // Create remaining after removing [L..R]
                    vector<int> chunk(arr.begin() + L, arr.begin() + R + 1);
                    vector<int> remaining;
                    remaining.insert(remaining.end(), arr.begin(), arr.begin() + L);
                    remaining.insert(remaining.end(), arr.begin() + R + 1, arr.end());

                    // Insert chunk at all positions in remaining
                    for (int pos = 0; pos <= (int)remaining.size(); pos++) {
                        vector<int> newArr = remaining;
                        newArr.insert(newArr.begin() + pos, chunk.begin(), chunk.end());

                        if (!visited.count(newArr)) {
                            visited.insert(newArr);
                            q.push({newArr, steps + 1});
                        }
                    }
                }
            }
        }

        return -1; // should never happen
    }
};