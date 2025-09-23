class Solution {
public:
    int digit1( int n){
            int sum=0;
            while(n>0){
                int temp=n%10;
                n=n/10;
                sum+=temp*temp;
            }
            return sum;
        }

    bool isHappy(int n) {
        // find digit in number...
        int nn=0;
        while(nn<100){
            int a=digit1(n);
            if(a==1){
                return true;
            }
            n=a;
            nn++;
        }
        return false;

        
    }
};