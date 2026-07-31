class Solution {
public:
    int f(int ind,vector<int> &dp){
        if(ind==0){
            return 0;
        }
        if(ind==1){
            return 1;
        }
        if(ind==2){
            return 1;
        }
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=f(ind-1,dp) + f(ind-2,dp)+f(ind-3,dp);
    }

    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};