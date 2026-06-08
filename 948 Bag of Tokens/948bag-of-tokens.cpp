class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int l=0;
        int r=n-1;
        int score=0;
        int ans=0;
        while(l<=r){
            if(tokens[l]<=power){
                power-=tokens[l];
                score++;
                ans=max(ans,score);
                l++;
            }
            else if(score>0){
                score--;
                power+=tokens[r];
                r--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};