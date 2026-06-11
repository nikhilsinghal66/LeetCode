class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        vector<int> ans(n);
        int ind=n-1;
        while(l<=r){
            if(nums[l]*nums[l]>=nums[r]*nums[r]){
                ans[ind]=(nums[l]*nums[l]);
                l++;
            }
            else{
                ans[ind]=(nums[r]*nums[r]);
                r--;
            }
            ind--;
        }
        return ans;
    }
};