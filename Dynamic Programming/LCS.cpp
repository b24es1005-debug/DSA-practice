int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(
        n + 1,
        vector<int>(m + 1, 0)
    );/*dp[i][j] stores the length of the LCS of:
The first i characters of s1 (i.e., s1[0...i-1])
The first j characters of s2 (i.e., s2[0...j-1])*/
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {//if matches
                dp[i][j] =dp[i - 1][j - 1] + 1;      
            } else {
                dp[i][j] =max(dp[i - 1][j],dp[i][j - 1]);       
            }
        }
    }
    return dp[n][m];
}
//SPACE OPTIMISED 1D DP
int longestCommonSubsequence(string s1, string s2) {
    if (s1.size() < s2.size()) swap(s1, s2);

    int m = s2.size();
    vector<int> dp(m + 1, 0);

    for (int i = 1; i <= s1.size(); i++) {
        int prev_diag = 0; // dp[i-1][j-1] before update
        for (int j = 1; j <= m; j++) {
            int temp = dp[j]; // store dp[i-1][j] (will become dp[i-1][j-1] for next j)
            if (s1[i - 1] == s2[j - 1]) {
                dp[j] = prev_diag + 1;
            } else {
                dp[j] = max(dp[j], dp[j - 1]);
            }
            prev_diag = temp;
        }
    }
    return dp[m];
}