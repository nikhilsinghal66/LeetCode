class Solution {
public:
    long long check(long long ans, long long count){
        long long ans1=(count*(count+1))/2;
        return ans1;

    }

    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        long long i=0;
        while(i<nums.size()){
            if(nums[i]==0){
                long long count=0;
                while(i < nums.size() && nums[i]==0){
                    i++;
                    count++;
                }
                ans+=check(ans,count);
            
            }
            else{
                i++;
            }
        }
        return ans;
    }
};