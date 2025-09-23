class Solution {
public:
    string makestring(string s){
        string str1="";
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(isalpha(ch) || isdigit(ch)){
                str1+=tolower(s[i]);
            }
        }
        return str1;
    }
    bool palindrome(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]!=s[s.size()-i-1]){
                return false;
            }
        }
        return true;
    }

    bool isPalindrome(string s) {
        string str=makestring(s);
        return (palindrome(str));
    }
};