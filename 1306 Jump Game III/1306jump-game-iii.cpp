class Solution {
public:
    bool f(int ind, vector<int> &arr, vector<int> &dp){
        if(ind<0 || ind>=arr.size()){
            return false;
        }
        if(arr[ind]==0){
            return true;
        }
        if(dp[ind]) return false;
        dp[ind]=1;
        bool right=f(ind+arr[ind],arr,dp);
        bool left=f(ind-arr[ind],arr,dp);
        return dp[ind]=right || left;
    }

    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> dp(n,0);
        return f(start,arr,dp);
    }
};