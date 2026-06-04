class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        //Sliding window...
        long long n=nums.size();
        map<int,int> mpp;
        int l=0;
        long long count=0;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            while(mpp.rbegin()->first - mpp.begin()->first >2){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            count+=(i-l+1);
        }
        return count;
    }
};