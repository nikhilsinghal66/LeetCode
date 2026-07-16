#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0;
        int l=0;
        unordered_map<char,int> mpp;
        for(int i=0;i<n;i++){
            if(mpp.find(s[i])!=mpp.end()){
                l=max(l,mpp[s[i]]+1);
            }
            mpp[s[i]]=i;
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};