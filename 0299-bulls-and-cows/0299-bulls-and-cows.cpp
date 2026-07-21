class Solution {
public:
    string getHint(string secret, string guess) {
        int n=guess.size();
        int count_a=0;
        int count_b=0;
        unordered_map<char,int> mpp;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                count_a++;
            }
            else{
                mpp[secret[i]]++;
            }
        }
        for(int i=0;i<n;i++){
            if(secret[i]!=guess[i]){
                if(mpp.find(guess[i])!=mpp.end()){
                    count_b++;
                    mpp[guess[i]]--;
                    if(mpp[guess[i]]==0){
                        mpp.erase(guess[i]);
                    }
                }
            }
        }
        string ans="";
        ans=to_string(count_a)+"A"+to_string(count_b)+"B";
        return ans;
    }
};