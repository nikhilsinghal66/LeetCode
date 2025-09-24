class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.size()){
            return s;
        }
        vector<string> vec(numRows);
        int i=0;
        int d=1;
        for(char c: s){
            vec[i]+=c;
            if(i==0) d=1;
            else if(i==numRows-1) d=-1;
            i+=d;
        }
        string result;
        for(auto j:vec){
            result+=j;
        }
        return result;
    }
};