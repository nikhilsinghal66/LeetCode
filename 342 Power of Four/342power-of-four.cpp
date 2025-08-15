class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0 || n==0) return false;
        while(n>1){
            int a=n%4;
            if(a!=0){
                return false;
            }
            n=n/4;
        }
        return true;
        
    }
};