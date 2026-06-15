class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //Padho with pratyush ... did this ques...
        //Nodelete ... onedelete...
        //skip this ...
        //Using sliding window...
        int n=nums.size();
        int l=0;
        int zeroes=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeroes++;
            }
            while(zeroes>1){
                if(nums[l]==0){
                    zeroes--;
                }
                l++;
            }
            ans=max(ans,(i-l));
        }
        return ans;
    }
};