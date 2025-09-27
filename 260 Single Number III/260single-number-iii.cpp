class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor1=nums[0];
        for(int i=1;i<nums.size();i++){
            xor1=xor1^nums[i];
        }
        long long diff=xor1 & (-xor1);
        int a=0;
        int b=0;
        for(auto num:nums){
            if(num & diff){
                a=a^num;
            }
            else{
                b=b^num;
            }
        }
        return {a,b};
        
    }
};