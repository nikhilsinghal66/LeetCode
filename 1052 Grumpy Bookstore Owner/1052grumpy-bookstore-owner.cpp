class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int l=0;
        int var=0;
        int satisfied=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                satisfied+=customers[i];
            }
        }
        //Now ,doing it max...
        int sum=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==1){
                sum+=customers[i];
            }
            var++;
            while(var>minutes){
                if(grumpy[l]==1){
                    sum-=customers[l];
                }
                var--;
                l++;
            }
            ans=max(ans,(sum));
        }
        return satisfied+ans;
    }
};