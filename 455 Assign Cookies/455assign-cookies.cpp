class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int i=0;
        int j=0;
        int count=0;
        while(j<g.size() && i<s.size()){
            if(s[i]>=g[j]){
                count++;
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return count;

        
    }
};