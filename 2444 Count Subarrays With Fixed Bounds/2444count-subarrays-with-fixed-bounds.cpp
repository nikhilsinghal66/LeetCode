class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long n=nums.size();
        int lastbad=-1;
        int lastmin=-1;
        int lastmax=-1;
        long long count=0;
        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK){
                lastbad=i;
            }
            if(nums[i]==minK){
                lastmin=i;
            }
            if(nums[i]==maxK){
                lastmax=i;
            }
            count+=max(0,min(lastmin,lastmax)-lastbad);
        }
        return count;
    }
};