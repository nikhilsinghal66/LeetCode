class Solution {
public:
    int pivotInteger(int n) {
        long long total_sum=0;
        int m=n;
        if(n==1){
            return 1;
        }
        while(n>=0){
            total_sum+=n;
            n--;
        }
        long long sum=0;
        for(int i=1;i<=m;i++){
            sum+=i;
            if(total_sum-sum+i==sum){
                return i;
            }
        }
        return -1;
    }
};