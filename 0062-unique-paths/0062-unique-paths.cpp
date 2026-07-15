class Solution {
public:
    int f(int m,int n,vector<vector<int>> &dp,int row,int col){
        if(row<0 || col<0){
            return 0;
        }
        if(row==0 && col==0){
            return 1;
        }
        if(dp[row][col]!=-1) return dp[row][col];
        int top=f(m,n,dp,row-1,col);
        int left=f(m,n,dp,row,col-1);
        return dp[row][col]=top+left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m,n,dp,m-1,n-1);
    }
};