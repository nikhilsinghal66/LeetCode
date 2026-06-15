class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size();
        int m=word2.size();
        int i=0;
        int j=0;
        int p1=0;
        int p2=0;
        while(i<n && j<m){
            if(word1[i][p1]!=word2[j][p2]){
                return false;
            }
            p1++;
            p2++;
            if(p1==word1[i].size()){
                p1=0;
                i++;
            }
            if(p2==word2[j].size()){
                p2=0;
                j++;
            }
        }
        return i==n && j==m;
    }
};