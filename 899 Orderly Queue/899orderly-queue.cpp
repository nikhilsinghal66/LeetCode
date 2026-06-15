class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n=s.size();
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        string ans=s;
        for(int i=0;i<n;i++){
            string temp=s.substr(i)+s.substr(0,i);
            ans=min(temp,ans);
        }
        return ans;
    }
};