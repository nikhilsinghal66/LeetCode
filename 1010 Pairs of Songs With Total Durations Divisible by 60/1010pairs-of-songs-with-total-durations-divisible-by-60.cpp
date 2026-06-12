class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size();
        unordered_map<int,int> mpp;
        int ans=0;
        for(int i=0;i<n;i++){
            int sum=time[i];
            int rem=sum%60;
            ans+=mpp[(60-rem)%60];
            mpp[rem]++;
        }
        return ans;
    }
};