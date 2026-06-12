class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //Prefix_sum ...
        int n=nums.size();
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        int l=0;
        long long sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=(sum%k+k)%k;
            if(mpp.find(rem)!=mpp.end()){
                if(i-mpp[rem]>=2){
                    return true;
                }
            }
            else{
                mpp[rem]=i;
            }
        }
        return false;
    }
};