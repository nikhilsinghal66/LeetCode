class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_set<char> st1;
        unordered_set<char> st2;
        vector<int> vec1(26,0);
        vector<int> vec2(26,0);
        int i=0;
        int j=0;
        for(auto x:word1){
            st1.insert(x);
            vec1[x-'a']++;

        }
        for(auto x:word2){
            if(st1.find(x)==st1.end()){
                return false;
            }
            vec2[x-'a']++;
        }
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());
        return vec1==vec2; 
    }
};