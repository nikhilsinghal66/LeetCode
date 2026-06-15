class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        //sliding window...
        if(k<=1) return 0;
        int l=0;
        long long product=1;
        int ans=0;
        for(int i=0;i<n;i++){
            product*=nums[i];
            while(product>=k){
                product/=nums[l];
                l++;
            }
            ans+=(i-l+1);
        }
        return ans;
    }
};