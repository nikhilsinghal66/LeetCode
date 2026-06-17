class Solution {
public:
    bool isPerfectSquare(int num) {
        int low=0;
        int high=num;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long ans=1LL*mid*mid;
            if(ans==num){
                return true;
            }
            if(ans>num){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
};