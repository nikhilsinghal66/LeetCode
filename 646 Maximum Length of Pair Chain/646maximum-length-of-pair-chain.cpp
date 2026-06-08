class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        int right=pairs[0][1];
        int ans=1;
        for(int i=1;i<n;i++){
            int a1=pairs[i][1];
            int a0=pairs[i][0];
            if(right<a0){
                ans++;
                right=max(right,a1);
            }
        }
        return ans;
    }
};