class Solution {
public:
    void f(int ind,vector<int> &nums,set<vector<int>>&ans,vector<int> &temp){
        if(ind==nums.size()){
            ans.insert(temp);
            return;
        }
        f(ind+1,nums,ans,temp);
        temp.push_back(nums[ind]);
        f(ind+1,nums,ans,temp);
        temp.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> temp;
        f(0,nums,ans,temp);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};