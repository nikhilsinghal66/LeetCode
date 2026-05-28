class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<bool> check(n+1,false);
        for(int i=0;i<n;i++){
            check[nums[i]]=true;
        }
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(check[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};