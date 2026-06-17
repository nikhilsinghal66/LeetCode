class Solution {
public:
    long long f(int div,vector<int> &nums){
        long long count=0;
        for(int i=0;i<nums.size();i++){
            count+=((nums[i]+div-1)/div);
        }
        return count;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        long long high=0;
        for(auto x:nums){
            high+=x;
        }
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long divisor=f(mid,nums);
            if(divisor<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};