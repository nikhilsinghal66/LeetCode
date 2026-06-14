class Solution {
public:
    int f(int ind, int move,vector<int> &nums){
        int n=nums.size();
        return ((ind+move)%n+n)%n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        //slow and fast pointer...
        int n=nums.size();
        for(int i=0;i<n;i++){
            bool forward=nums[i]>0;
            int slow=i;
            int fast=i;
            while(true){
                int nextslow=f(slow,nums[slow],nums);
                if(nextslow==slow || (nums[nextslow]>0)!=forward){
                    break;
                }
                int nextfast=f(fast,nums[fast],nums);
                if(nextfast==fast || (nums[nextfast]>0)!=forward){
                    break;
                }
                int temp=f(nextfast,nums[nextfast],nums);
                if(temp==nextfast ||  (nums[temp]>0)!=forward){
                    break;
                }
                slow=nextslow;
                fast=temp;
                if(slow==fast){
                    return true;
                }
            }
        }
        return false;
    }
};