class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        int bestsum=nums[0];
        for(int i=1;i<n;i++){
            sum+=nums[i];
            sum=max(sum,nums[i]);
            bestsum=max(sum,bestsum);
        }
        return bestsum;
    }
};