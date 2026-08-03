class Solution {//LC1143 TC:O(NxM) SC:O(NxM)
private:
    // Recursive memoized function to compute LCS length for text1[0..idx1] and text2[0..idx2]
    int f(int idx1, int idx2, string& text1, string& text2, vector<vector<int>>& dp) {
        // Base case: empty prefix → LCS length is 0
        if (idx1 < 0 || idx2 < 0) return 0;
        // Return already computed result
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        // If characters match, include this character in LCS
        if (text1[idx1] == text2[idx2]) {
            return dp[idx1][idx2] = 1 + f(idx1 - 1, idx2 - 1, text1, text2, dp);
        }
        // Otherwise, skip one character from either string and take the maximum
        return dp[idx1][idx2] = max(f(idx1 - 1, idx2, text1, text2, dp),
                                    f(idx1, idx2 - 1, text1, text2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // dp[i][j] stores LCS length for text1[0..i] and text2[0..j], -1 means uncomputed
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, text1, text2, dp);
    }
};

class Solution {//Tabulation TC:O(NxM) SC:O(NxM) 2D DP
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        // dp[i][j] = LCS length for text1[0..i-1] and text2[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};

class Solution {//Space Optimized Tabulation TC:O(NxM) SC:O(M) 1D DP
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        // dp[j] represents LCS length for current i and prefix of text2 up to j
        vector<int> dp(m + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            int prev = 0;          // dp[i-1][0] is always 0
            for (int j = 1; j <= m; ++j) {
                int temp = dp[j];  // save dp[i-1][j] before overwriting
                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = 1 + prev;   // prev = dp[i-1][j-1]
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);  // dp[j] is still dp[i-1][j]
                }
                prev = temp;        // update prev to dp[i-1][j] for next j
            }
        }
        return dp[m];
    }
};