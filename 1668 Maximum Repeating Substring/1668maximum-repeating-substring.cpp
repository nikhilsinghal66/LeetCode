class Solution {
public:
    int maxRepeating(string sequence, string word) {

        int n = sequence.size();
        int m = word.size();
        int ans = 0;

        for(int i = 0; i < n; i++){

            int count = 0;
            int pos = i;

            while(pos + m <= n && sequence.substr(pos, m) == word){
                count++;
                pos += m;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};