class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i-1]==nums[i]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j-1]==nums[j]){
                    continue;
                }
                int low=j+1;
                int high=n-1;
                while(low<high){
                    long long sum=1LL*nums[i]+nums[j]+nums[low]+nums[high];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                        low++;
                        high--;
                        while(low<high && nums[low-1]==nums[low]){
                            low++;
                        }
                        while(low<high && nums[high]==nums[high+1]){
                            high--;
                        }
                    }
                    else if(sum<target){
                        low++;
                    }
                    else {
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};