class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> ans(26,0);
        for(int i=0;i<text.size();i++){
            ans[text[i]-'a']++;
        }
        int min1=INT_MAX;
        string balloon="balloon";
        for(auto x:balloon){
            if(x=='l' || x=='o'){
                min1=min(min1,ans[x-'a']/2);
            }
            else{
                min1=min(min1,ans[x-'a']);
            }
        }
        return min1;
    }
};