class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp;
        for (char c : t) {
            mpp[c]++;
        }
        int m=t.size();
        int l=0;
        int r=0;
        int count=0;
        int start=-1;
        int minlen=INT_MAX;
        while(r<s.size()){
            mpp[s[r]]--;
            if(mpp[s[r]]>=0) count++;
            while(count==m){
                char temp=s[l];
                if(minlen>(r-l+1)){
                    minlen=r-l+1;
                    start=l;
                }
                l++;
                mpp[temp]++;
                if(mpp[temp]>0) count--;
            }
            r++;
        }
        return start==-1?"":s.substr(start,minlen);
        
    }
};