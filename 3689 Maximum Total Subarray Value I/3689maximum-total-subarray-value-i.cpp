class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        long long min1=INT_MAX;
        long long max1=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]<min1){
                min1=nums[i];
            }
            if(nums[i]>max1){
                max1=nums[i];
            }
        }
        return (max1-min1)*k;
    }
};