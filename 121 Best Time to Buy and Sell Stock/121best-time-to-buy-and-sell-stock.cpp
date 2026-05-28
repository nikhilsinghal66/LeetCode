class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=INT_MIN;
        int n=prices.size();
        int stock=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<stock){
                stock=prices[i];
            }
            else{
                ans=max(ans,abs(prices[i]-stock));
            }
        }
        return ans==INT_MIN?0:ans; 
    }
};