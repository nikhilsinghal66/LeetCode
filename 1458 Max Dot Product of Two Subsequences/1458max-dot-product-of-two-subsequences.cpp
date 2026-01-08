class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // Very small value to represent impossible states
        const int NEG_INF = -1e9;

        // dp[i][j] = max dot product using nums1[0..i-1] & nums2[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, NEG_INF));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int prod = nums1[i - 1] * nums2[j - 1];

                dp[i][j] = max({
                    prod,                    // start new subsequence
                    prod + dp[i - 1][j - 1], // extend previous subsequence
                    dp[i - 1][j],            // skip nums1[i-1]
                    dp[i][j - 1]             // skip nums2[j-1]
                });
            }
        }

        return dp[n][m];
    }
};