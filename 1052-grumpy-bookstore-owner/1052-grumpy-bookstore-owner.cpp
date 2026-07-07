class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                ans+=customers[i];
            }
        }
        int ans1=0;
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1){
                ans1+=customers[i];
            }
        }
        int maxAns=ans1;
        for(int i=minutes;i<n;i++){
            if(grumpy[i]==1){
                ans1+=customers[i];
            }
            if(grumpy[i-minutes]==1){
                ans1-=customers[i-minutes];
            }
            maxAns=max(maxAns,ans1);
        }
        return ans+maxAns;
    }
};