class Solution {
public:
    long long f(vector<vector<int>> &grid,int n,int m,vector<vector<int>> &dp){
        if(n==0 && m==0){
            return grid[0][0];
        }
        if(n<0 || m<0){
            return INT_MAX;
        }
        if(dp[n][m]!=-1) return dp[n][m];
        long long up=grid[n][m]+f(grid,n-1,m,dp);
        long long left=grid[n][m]+f(grid,n,m-1,dp);
        return dp[n][m]=min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return f(grid,n-1,m-1,dp);
    }
};