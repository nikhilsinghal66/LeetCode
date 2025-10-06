class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        unordered_map<char,int> mpp;
        int sum=0;
        int n=s.size();
        int mostfre=0;
        while(r<n){
            mpp[s[r]-'A']++;
            mostfre=max(mostfre,mpp[s[r]-'A']);
            if(((r-l+1)-mostfre)>k){
                mpp[s[l]-'A']--;
                l++;
            }
            sum=max(sum,r-l+1);
            r++;
        }
        return sum;

        
    }
};