class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int l=0;
        int sum=0;
        int total_sum=0;
        for(auto y:nums){
            total_sum+=y;
        }
        int k=total_sum-x;
        if (k < 0) return -1;
        if (k == 0) return nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            if(sum==k){
                ans=max(ans,i-l+1);
            }
        }
        return ans==INT_MIN?-1:n-ans;
    }
};