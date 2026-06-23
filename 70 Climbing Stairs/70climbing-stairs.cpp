class Solution {
public:
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // dp[0]=1;
        int prev=1;
        int prev2=-1;
        for(int i=1;i<=n;i++){
            int left=prev;
            int right=0;
            if(i-2>=0){
                right=prev2;
            }
            int curr=left+right;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};












