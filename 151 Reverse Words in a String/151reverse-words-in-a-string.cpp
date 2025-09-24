class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        string str="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                str+=s[i];
            }
            else if(!str.empty()){
                vec.push_back(str);
                str="";
            }
        }
        if(!str.empty()) vec.push_back(str);
        reverse(vec.begin(),vec.end());
        string str1="";
        for(int i=0;i<vec.size();i++){
            str1+=vec[i];
            if(i!=vec.size()-1) str1+=' ';

        }
        return str1;
        
    }
};