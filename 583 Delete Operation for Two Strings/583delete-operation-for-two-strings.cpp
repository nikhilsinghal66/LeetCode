class Solution {
public:
    int f(string word1,string word2,int n ,int m,vector<vector<int>> &dp){
        //Base case...
        if(n==0 || m==0){
            return 0;
        }
        if(dp[n][m]!=-1) return dp[n][m];
        //Take...
        if(word1[n-1]==word2[m-1]){
            return dp[n][m]=1+f(word1,word2,n-1,m-1,dp);
        }
        //Not_take...
        return dp[n][m]=max(f(word1,word2,n-1,m,dp),f(word1,word2,n,m-1,dp));
    }

    int minDistance(string word1, string word2) {
        //Longest palindromic subsequence...
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                } 
            }
        }
        return n+m-2*dp[n][m];
    }
};