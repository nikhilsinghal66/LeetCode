class Solution {
public:
    void f(int ind,int target,vector<int> &candidates,vector<vector<int>> &ans,vector<int> &temp,int n){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<n;i++){
            if(i>ind && candidates[i-1]==candidates[i]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            temp.push_back(candidates[i]);
            f(i+1,target-candidates[i],candidates,ans,temp,n);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(0,target,candidates,ans,temp,n);
        return ans;
    }
};