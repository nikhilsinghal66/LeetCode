class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Optimal Appraoch...
        int n=prices.size();
        int min1=prices[0];
        int ans=0;
        for(int i=1;i<n;i++){
            if(min1>prices[i]){
                min1=prices[i];
            }
            else{
                ans=max(ans,prices[i]-min1);
            }
        }
        return ans;
    }
};