class Solution {
public:
    int f(int ind , vector<int> &cost,vector<int> &dp){
        if(ind==0){
            return cost[ind];
        }
        if(ind==1){
            return cost[ind];
        }
        if(dp[ind]!=-1) return dp[ind];
        int first_step=cost[ind]+f(ind-1,cost,dp);
        int second_step=cost[ind]+f(ind-2,cost,dp);
        return dp[ind]=min(first_step,second_step);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        int ans=min(f(n-1,cost,dp),f(n-2,cost,dp));
        return ans;
    }
};