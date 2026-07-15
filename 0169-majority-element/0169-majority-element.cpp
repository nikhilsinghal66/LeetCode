class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Better Approach...
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(auto x:nums){
            mpp[x]++;
        }
        for(auto it:mpp){
            if(it.second>n/2){
                return it.first;
            }
        }
        return -1;
    }
};