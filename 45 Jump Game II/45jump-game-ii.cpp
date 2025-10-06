class Solution {
public:
    int jump(vector<int>& nums) {
        int result=0;
        int farthest=0;
        int location=0;
        for(int i=0;i<nums.size()-1;i++){
            farthest=max(farthest,i+nums[i]);
            if(i==location){
                result++;
                location=farthest;
            }
        }
        return result;
        
    }
};