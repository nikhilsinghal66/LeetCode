class Solution {
public:
    void put1(vector<string> &vec, string s){
        string str="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                str+=s[i];
            }
            else{
                vec.push_back(str);
                str="";
            }
        }
        vec.push_back(str);
    }
    bool wordPattern(string pattern, string s) {
        map<char, string> mpp;
        map<string , char> mpp1;
        
        vector<string> vec;
        put1(vec,s);
        if(vec.size() != pattern.size()) return false;
        for(int i=0;i<pattern.size();i++){
            if(mpp.find(pattern[i])!=mpp.end()){
                if(mpp[pattern[i]]==vec[i] ){
                    continue;
                }
                else{
                    return false;
                }
            }
            else{
                mpp[pattern[i]]=vec[i];
            }
            if(mpp1.find(vec[i])!=mpp1.end()){
                if(mpp1[vec[i]]==pattern[i] ){
                    continue;
                }
                else{
                    return false;
                }
            }
            else{
                mpp1[vec[i]]=pattern[i];
            }

        }
        return true;  
    }
};