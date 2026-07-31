class Solution {
public:
    int f(int ind,vector<int> &nums,vector<int> &dp){
        if(ind==0){
            return nums[ind];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int first_house=f(ind-1,nums,dp);
        int second_house=0;
        if(ind-1>=0){
            second_house=nums[ind]+f(ind-2,nums,dp);
        }
        return dp[ind]=max(first_house,second_house);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        if(n==1){
            return nums[0];
        }
        return f(n-1,nums,dp);
    }
};