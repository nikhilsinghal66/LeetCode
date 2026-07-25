class Solution {
public:
    int f(int ind ,string num,vector<int> &ans,int n){
        if(ind==n){
            return ans.size()>=3;
        }
        long long curr=0;
        for(int i=ind;i<n;i++){
            if(i>ind && num[ind]=='0'){
                break;
            }
            curr=(long long)curr*10+(num[i]-'0');
            if(curr>INT_MAX){
                break;
            }
            if(ans.size()>=2){
                long long expectation=(1LL*ans[ans.size()-1]+ans[ans.size()-2]);
                if(curr<expectation){
                    continue;
                }
                if(curr>expectation){
                    break;
                }
            }
            ans.push_back(curr);
            if(f(i+1,num,ans,n)){
                return true;
            }
            ans.pop_back();
        }
        return false;
    }

    vector<int> splitIntoFibonacci(string num) {
        int n=num.size();
        vector<int> ans;
        f(0,num,ans,n);
        return ans;
    }
};