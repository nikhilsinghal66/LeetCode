class Solution {
public:
    int uniquePaths(int m, int n) {
        //Tabulation...
        vector<vector<long long>> dp(m+1,vector<long long> (n+1,0));
        dp[0][0]=1;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 && j==0) continue;
                long long left= (i>0) ? dp[i-1][j]:0;
                long long right=(j>0) ? dp[i][j-1]:0;
                dp[i][j]=left+right;
            }
        }
        return dp[m-1][n-1];   
    }
};