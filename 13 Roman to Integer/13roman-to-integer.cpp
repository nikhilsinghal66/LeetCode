class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mpp={{'M',1000},{'D',500},{'C',100},
        {'L',50},{'X',10},{'V',5},{'I',1}};
        int n=s.size();
        int num=0;
        for(int i=0;i<n;i++){
            if(i<n-1 && mpp[s[i]]<mpp[s[i+1]]){
                num-=mpp[s[i]];
            }
            else{
                num+=mpp[s[i]];
            }
        }
        return num;
    }
};