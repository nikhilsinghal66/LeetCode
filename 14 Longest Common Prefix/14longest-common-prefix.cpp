class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //Brute force ...
        string temp=strs[0];
        string ans="";
        for(int i=0;i<temp.size();i++){
            char tmp=temp[i];
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=tmp){
                    return ans;
                }
            }
            ans+=tmp;
        }
        return ans;
    }
};