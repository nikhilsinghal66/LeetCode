class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mpp;
        string ss="abc";
        for(int i=0;i<3;i++){
            mpp[ss[i]]=-1;
        }
        char a='a',b='b',c='c';
        int l=0;
        int r=0;
        int count=0;
        while(r<s.size()){
            mpp[s[r]]=r;
            if(mpp['a']!=-1 && mpp['b']!=-1 && mpp['c']!=-1){
                int temp=min(mpp['a'],mpp['b']);
                count+=(1+min(temp, mpp['c']));
            }
            r++;
        }
        return count;
    }
};