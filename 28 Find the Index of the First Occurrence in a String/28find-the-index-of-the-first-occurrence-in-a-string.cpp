class Solution {
public:
    bool  check(string haystack,string needle , int index){
        int temp=0;
        for(int i=0;i<needle.size();i++){
            if(haystack[index]==needle[temp]){
                temp++;
                index++;
                continue;
            }
            else {
                return false;
            }
            temp++;
            index++;
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        int ans=-1;
        for(int i=0;i<haystack.size();i++){
            if(needle[0]==haystack[i]){
                if(check(haystack,needle,i)==true){
                    ans=i;
                    break;
                }
            }
        }
        return ans;
        
    }
};