class Solution {
public:
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    string substring(const string& s, int i, int j) {
        string ans = "";
        for (int k = i; k <= j; k++) {
            ans += s[k];
        }
        return ans;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int maxLen = 0;
        string answer = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    int len = j - i + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        answer = substring(s, i, j);
                    }
                }
            }
        }

        return answer;
    }
};