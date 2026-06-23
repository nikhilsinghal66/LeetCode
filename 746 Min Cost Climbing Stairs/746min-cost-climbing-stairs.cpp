class Solution {
public:
    int f(int n,vector<int> &dp,vector<int> &cost){
        if(n<=1){
            return cost[n];
        }
        if(dp[n]!=-1) return dp[n];
        int left=f(n-1,dp,cost)+cost[n];
        int right=0;
        if(n-2>=0){
            right=f(n-2,dp,cost)+cost[n];
        }
        return dp[n]=min(left,right);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(f(n-1,dp,cost),f(n-2,dp,cost));
    }
};