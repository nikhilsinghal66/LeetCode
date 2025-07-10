class Solution {
public:
    int secondHighest(string s) {
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                ans.push_back(s[i]-'0');
            }
        }
        int largest=-1;
        int second=-1;
        for(auto it:ans){
            if(it>largest){
                second=largest;
                largest=it;
            }
            else if( it<largest && it > second){
                second=it;

            }
        }
        return second; 
    }
};