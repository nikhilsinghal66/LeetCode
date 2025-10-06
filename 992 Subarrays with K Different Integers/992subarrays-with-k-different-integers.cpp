class Solution {
public:
    int findk(vector<int> nums,int k){
        if(k<0) return 0;
        int l=0;
        int r=0;
        unordered_map<int,int> mpp;
        int n=nums.size();
        int count=0;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans1=findk(nums,k);
        int ans2=findk(nums,k-1);
        return ans1-ans2;
    }
};