class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                sum++;
            }
            ans+=mpp[sum-k];
            mpp[sum]++;
        }
        return ans;
    }
};