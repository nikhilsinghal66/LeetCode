class Solution {
public:
    void f(vector<int> &nums,vector<vector<int>> &ans,vector<int> &temp,vector<int> &visited){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]==0){
                temp.push_back(nums[i]);
                visited[i]=1;
                f(nums,ans,temp,visited);
                visited[i]=0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> visited(n,0);
        f(nums,ans,temp,visited);
        return ans;
    }
};