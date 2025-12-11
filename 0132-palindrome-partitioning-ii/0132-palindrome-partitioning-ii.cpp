class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // Step 1: Precompute palindrome table
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        // Step 2: DP for minimum cuts
        vector<int> dp(n, INT_MAX);

        for (int i = 0; i < n; i++) {
            if (isPal[0][i]) {
                dp[i] = 0;  // whole substring is palindrome
            } else {
                for (int j = 1; j <= i; j++) {
                    if (isPal[j][i]) {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};
