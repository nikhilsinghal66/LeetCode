class Solution {
public:
    int fib(int n){
        if(n==0) return 0;
        vector<int> dp(n+1,0);
        int prev2=0;
        int prev=1;
        for(int i=2;i<=n;i++){
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