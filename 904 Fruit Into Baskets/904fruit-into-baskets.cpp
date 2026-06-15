class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        //Using prefix sum...
        unordered_map<int,int> mpp;
        int l=0;
        int ans=0;
        for(int i=0;i<n;i++){
            mpp[fruits[i]]++;
            while(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};