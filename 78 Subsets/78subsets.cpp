class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int num=1<<nums.size();
        vector<vector<int>> result;
        for(int i=0;i<num;i++){
            vector<int> ans;
            for(int j=0;j<nums.size();j++){
                if(i & (1<<j)){
                    ans.push_back(nums[j]);
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};