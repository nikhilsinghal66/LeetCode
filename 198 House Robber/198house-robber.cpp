class Solution {
public:
    int f(int n,vector<int> &nums,vector<int> &dp){
        if(n<0){
            return 0;
        }
        if(n==0){
            return nums[n];
        }
        if(dp[n]!=-1) return dp[n];
        int not_take=0+ f(n-1,nums,dp);
        int take=f(n-2,nums,dp)+nums[n];
        return dp[n]=max(take,not_take);  
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        //dp[i]=n...
        vector<int> dp(n+1,-1);
        return f(n-1,nums,dp);
    }
};