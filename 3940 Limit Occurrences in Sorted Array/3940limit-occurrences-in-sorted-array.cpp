class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        int count=0;
        int temp=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]==temp && count<k){
                ans.push_back(nums[i]);
                count++;
            }
            else if(nums[i]!=temp ){
                ans.push_back(nums[i]);
                temp=nums[i];
                count=1;
            }
            else if(count>k){
                continue;
            }
        }
        return ans;
    }
};