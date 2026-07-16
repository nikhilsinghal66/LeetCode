class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int currentCount=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                currentCount++;
                ans=max(ans,currentCount);
            }
            else{
                currentCount=0;
            }
        }
        return ans;
    }
};