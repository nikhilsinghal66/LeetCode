class Solution {
public:
    long long countVowels(string word) {
        unordered_map<char,int> mpp;
        mpp['a']=1;
        mpp['e']=1;
        mpp['i']=1;
        mpp['o']=1;
        mpp['u']=1;
        long long ans=0;
        for(int i=0;i<word.size();i++){
            if(mpp.find(word[i])!=mpp.end()){
                ans += 1LL * (i + 1) * (word.size()- i);
            }
        }
        return ans;
    }
};