int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(
        n + 1,
        vector<int>(m + 1, 0)
    );
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {//if matches
                dp[i][j] =
                    dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] =
                    max(
                        dp[i - 1][j],
                        dp[i][j - 1]
                    );
            }
        }
    }

    return dp[n][m];
}/*dp[i][j] stores the length of the LCS of:

The first i characters of s1 (i.e., s1[0...i-1])

The first j characters of s2 (i.e., s2[0...j-1])*/