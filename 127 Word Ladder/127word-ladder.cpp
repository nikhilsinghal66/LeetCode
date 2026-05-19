class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        unordered_set<string> set_vis;
        for(auto it:wordList){
            st.insert(it);
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        set_vis.insert(beginWord);
        while(!q.empty()){
            auto it=q.front();
            string word=it.first;
            int moves=it.second;
            q.pop();
            if(word==endWord) return moves;
            // for( 1 ,2, 3)...
            // for (a to z ) for every index of word...
            for(int i=0;i<word.size();i++){
                string temp=word;
                for(char ch='a';ch<='z';ch++){
                    temp[i]=ch;
                    if(st.count(temp) && !set_vis.count(temp)){
                        q.push({temp,moves+1});
                        set_vis.insert(temp);
                    }
                }
            }
        }
        return 0;
    }
};