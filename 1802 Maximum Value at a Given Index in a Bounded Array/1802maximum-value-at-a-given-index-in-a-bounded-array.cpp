class Solution {
public:
    long long f(long long peak, long long len){
        if(peak >= len){
            long long last = peak - len + 1;
            return (peak + last) * len / 2;
        }
        else{
            long long sum = peak * (peak + 1) / 2;
            sum += (len - peak);
            return sum;
        }
    }

    int maxValue(int n, int index, int maxSum) {
        //Binary Search...
        int low=1;
        int high=maxSum;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long left=f(mid-1,index);
            long long right=f(mid-1,n-index-1);
            long long ans=left+right+mid;
            if(ans<=maxSum){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};