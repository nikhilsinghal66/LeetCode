class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max1=nums[0];
        int curr_max=nums[0];
        for(int i=1;i<n;i++){
            int temp=nums[i];
            curr_max=max(curr_max+nums[i],temp);
            max1=max(max1,curr_max);
            if(curr_max<0){
                curr_max=0;
            }
        }
        return max1;
    }
};