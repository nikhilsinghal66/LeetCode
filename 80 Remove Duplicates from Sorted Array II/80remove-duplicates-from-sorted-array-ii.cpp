class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        int l=1;
        int number=nums[0];
        int counter=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i] && count<2){
                nums[l]=nums[i];
                count++;
                l++;
                counter++;
            }
            else if(nums[i-1]==nums[i] && count>=2){
                continue;
            }
            else{
                nums[l]=nums[i];
                count=1;
                l++;
                counter++;
            }
        }
        return counter;
    }
};