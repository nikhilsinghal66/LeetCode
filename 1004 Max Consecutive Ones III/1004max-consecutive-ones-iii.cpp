class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //Sliding window...
        int n=nums.size();
        int l=0;
        int ans=0;
        int var=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                var++;
            }
            while(var>k){
                if(nums[l]==0){
                    var--;
                }
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};