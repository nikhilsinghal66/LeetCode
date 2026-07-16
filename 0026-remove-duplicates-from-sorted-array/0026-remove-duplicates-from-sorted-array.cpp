class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Sorted ... 
        int n=nums.size();
        if(n==1){
            return n;
        }
        int l=0;
        for(int i=1;i<n;i++){
            if(nums[l]==nums[i]){
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
