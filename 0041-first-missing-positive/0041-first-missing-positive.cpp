class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int r=0;
        while(r<n){
            if(nums[r]<=0 || nums[r]>n){
                r++;
            }
            else if(nums[r]==r+1){
                r++;
            }
            else if(nums[r]==nums[nums[r]-1]){
                r++;
            }
            else{
                swap(nums[r],nums[nums[r]-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};