class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long sum=0;
        int ans=0;
        int l=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while((long long)nums[i]*(i-l+1) - sum > k){
                sum-=nums[l];
                l++;
            }
            ans=max(ans,(i-l+1));
        }
        return ans;
    }
};