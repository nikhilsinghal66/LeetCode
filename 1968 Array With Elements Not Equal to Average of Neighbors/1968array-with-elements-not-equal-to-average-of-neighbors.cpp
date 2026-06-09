class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        int l=0;
        sort(nums.begin(),nums.end());
        int r=n-1;
        while(l<=r){
                ans.push_back(nums[l]);
                l++;
                if(l<=r){
                ans.push_back(nums[r]);
                r--;
                }
        }
        return ans;
    }
};