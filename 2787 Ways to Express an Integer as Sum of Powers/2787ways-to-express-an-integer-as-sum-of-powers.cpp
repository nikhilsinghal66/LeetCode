class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;
        
        // Step 1: Precompute powers
        vector<int> powers;
        for (int i = 1; pow(i, x) <= n; i++) {
            powers.push_back(pow(i, x));
        }

        int m = powers.size();
        
        // Step 2: DP array
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1; // 1 way to make sum = 0 (choose nothing)

        // Step 3: Fill DP
        for (int i = 1; i <= m; i++) {
            int p = powers[i - 1];
            for (int sum = 0; sum <= n; sum++) {
                // exclude current power
                dp[i][sum] = dp[i-1][sum];
                // include current power if possible
                if (sum >= p) {
                    dp[i][sum] = (dp[i][sum] + dp[i-1][sum - p]) % MOD;
                }
            }
        }

        return dp[m][n];
    }
};