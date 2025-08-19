class Solution {
public:
    bool isIsomorphic(string s, string t) {
         vector<int> mpp(256,-1);
         vector<int> mpp1(256,-1);
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            if(mpp[s[i]]==-1 && mpp1[t[i]]==-1){
                mpp[s[i]]=t[i];
                mpp1[t[i]]=s[i];

            }
            else if(mpp[s[i]]!=t[i] ||  mpp1[t[i]]!=s[i] ){
                return false;
            }
        }
        return true; 
    }
};