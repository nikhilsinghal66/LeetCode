class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int initialOnes=0;
        for(char c : s){
            if(c=='1'){
                initialOnes++;
            }
        }
        s.insert(s.begin(),'1');
        s.push_back('1');
        int t=s.size();
        vector<pair<char,int>> mpp;
        int count=1;
        for(int i=1;i<t;i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                mpp.push_back({s[i-1],count});
                count=1;
            }
        }
        mpp.push_back({s[t-1],count});
        int ans=initialOnes;
        for(int i=1;i<mpp.size()-1;i++){
            if(mpp[i-1].first=='0' && mpp[i].first=='1' && mpp[i+1].first=='0'){
                ans=max(mpp[i-1].second + initialOnes+ mpp[i+1].second,ans);
            }
        }
        return ans;
        
    }
};