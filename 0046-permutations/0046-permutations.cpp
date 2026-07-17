class Solution {
public:
    void f(int ind,vector<vector<int>> &ans,vector<int> &nums,int n){
        if(ind==n){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<n;i++){
            swap(nums[i],nums[ind]);
            f(ind+1,ans,nums,n);
            swap(nums[i],nums[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        f(0,ans,nums,n);
        return ans;
    }
};