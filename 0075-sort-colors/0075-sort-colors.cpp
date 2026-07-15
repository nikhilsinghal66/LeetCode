class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        //Optimal Approach...
        int zero=0;
        int two=n-1;
        int i=0;
        while(i<=two){
            if(nums[i]==0){
                swap(nums[zero],nums[i]);
                i++;
                zero++;
            }
            else if(nums[i]==1){
                i++;
            }
            else{
                swap(nums[i],nums[two]);
                two--;
            }
        }
    }
};