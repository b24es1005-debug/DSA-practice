class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;
        int maxLen = 1;

        // Every single character is a palindrome
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        // Check substrings of increasing length
        for (int len = 2; len <= n; len++) {

            // Starting index
            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j]) {

                    // Length 2 or 3 doesn't need an inner check
                    if (len <= 3)
                        dp[i][j] = true;

                    // Otherwise, inner substring must also be palindrome
                    else if (dp[i + 1][j - 1])
                        dp[i][j] = true;
                }

                // Update answer
                if (dp[i][j] && len > maxLen) {
                    maxLen = len;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};