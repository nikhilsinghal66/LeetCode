class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[l]){
                continue;
            }
            else{
                l++;
                nums[l]=nums[i];
            }
        }
        return l+1;
    }
};