class Solution {
public:
    int f(int n,vector<int> &dp){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1) return dp[n];
        int first_step=f(n-1,dp);
        int second_step=f(n-2,dp);
        return dp[n]=first_step+second_step;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};