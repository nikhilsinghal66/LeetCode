class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=nums[0];
        for(int i=1;i<n;i++){
            if(ans==nums[i]){
                return true;
            }
            else{
                ans=nums[i];
            }
        }
        return false;
        
    }
};