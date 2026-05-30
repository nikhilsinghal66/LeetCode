class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        long long total_sum=0;
        for(auto it:nums){
            total_sum+=it;
        }
        if(total_sum%p==0){
            return 0;
        }
        mpp[0]=-1;
        long long sum=0;
        int result=nums.size();
        int target=total_sum%p;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%p;
            int needed=(rem-target+p)%p;
            if(mpp.find(needed)!=mpp.end()){
                result=min(result,i-mpp[needed]);
            }
            mpp[rem]=i;
        }
        return result==n?-1:result;
    }
};