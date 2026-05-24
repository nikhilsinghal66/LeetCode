class Solution {
public:
    int passwordStrength(string password) {
        int ans=0;
        int n=password.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            if(password[i]>='a' && password[i]<='z' &&
               mpp.find(password[i])==mpp.end()){
                ans+=1;
                mpp[password[i]]++;
            }
            else if(password[i]>='A' && password[i]<='Z' && 
                    mpp.find(password[i])==mpp.end()){
                ans+=2;
                mpp[password[i]]++;
            }
            else if(password[i]>='0' && password[i]<='9' && 
                    mpp.find(password[i])==mpp.end()){
                ans+=3;
                mpp[password[i]]++;
            }
            else{
                if(mpp.find(password[i])==mpp.end()){
                    ans+=5;
                    mpp[password[i]]++;
                }
            }
        }
        return ans;
    }
};