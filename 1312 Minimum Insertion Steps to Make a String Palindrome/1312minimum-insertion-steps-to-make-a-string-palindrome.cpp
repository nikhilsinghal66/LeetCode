class Solution {
public:
    int minInsertions(string s) {
          string ss=s;
          reverse(s.begin(),s.end());
          int n=s.size();
          vector<vector<int>> dp(n+1,vector<int> (n+1,0));
          int size1=s.size();
          for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int take=0;
                if(ss[i-1]==s[j-1]){
                    dp[i][j]= 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                } 
            }
          }
          return size1-dp[n][n];
    }
};