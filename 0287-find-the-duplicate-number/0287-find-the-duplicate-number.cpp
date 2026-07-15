class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Hare and tortoise method
        //Slow and fast pointer...
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[fast];
            fast=nums[fast];
        }while(slow!=fast);
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};