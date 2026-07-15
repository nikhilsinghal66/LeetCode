class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Optimal Appraoch...
        int n=prices.size();
        int max1=prices[n-1];
        int ans=0;
        for(int i=n-2;i>=0;i--){
            if(prices[i]>max1){
                max1=prices[i];
            }
            else{
                ans=max(ans,max1-prices[i]);
            }
        }
        return ans;
    }
};