class Solution {
public:
    string countAndSay(int n) {
        //doing with recursion...
        if(n==1){
            return "1";
        }
        string ans=countAndSay(n-1);
        string result="";
        for(int i=0;i<ans.size();i++){
            int count=1;
            char temp=ans[i];
            while(i<ans.size()-1 && ans[i]==ans[i+1]){
                count++;
                i++;
            }
            result+=to_string(count)+string(1,temp);
        }
        return result;
    }
};