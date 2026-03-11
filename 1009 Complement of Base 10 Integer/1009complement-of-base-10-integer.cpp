class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        string s="";
        while(n>0){
            s+=(n%2)+'0';
            n=n/2;
        }
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                s[i]='0';
            }
            else{
                s[i]='1';
            }
        }
        int result=0;
        int temp=1;
        for(int i=s.size()-1;i>=0;i--){
            result+=temp*(s[i]-'0');
            temp*=2;
        }
        return result;  
    }
};