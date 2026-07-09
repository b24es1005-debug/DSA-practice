// ================================================================
// LEETCODE 62 - Unique Paths
// ================================================================

class Solution {
public:
    // TYPE 1: 2D DP Tabulation
    // T.C: O(m*n), S.C: O(m*n)
    int uniquePaths2D(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Base cases: First row and first column have only 1 way
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;
        
        // Fill the DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // From above + From left
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
    
    // TYPE 2: Space Optimized (1D DP)
    // T.C: O(m*n), S.C: O(n)
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);  // All 1 for first row
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // dp[j] (above) + dp[j-1] (left)
                dp[j] = dp[j] + dp[j-1];
            }
        }
        
        return dp[n-1];
    }
    
    // TYPE 3: Memoization (Top-Down)
    // T.C: O(m*n), S.C: O(m*n) + recursion stack
    int uniquePathsMemo(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solve(m-1, n-1, memo);
    }
    
    int solve(int i, int j, vector<vector<int>>& memo) {
        // Base cases
        if (i == 0 || j == 0) return 1;
        if (memo[i][j] != -1) return memo[i][j];
        
        // Recurrence
        return memo[i][j] = solve(i-1, j, memo) + solve(i, j-1, memo);
    }
    
    // TYPE 4: Mathematical (Combinations)
    // T.C: O(min(m,n)), S.C: O(1)
    int uniquePathsMath(int m, int n) {
        long long ans = 1;
        // Need to choose (m-1) downs from (m+n-2) total moves
        // C(m+n-2, m-1) or C(m+n-2, n-1)
        int N = m + n - 2;
        int r = min(m, n) - 1;
        
        for (int i = 1; i <= r; i++) {
            ans = ans * (N - r + i) / i;
        }
        
        return ans;
    }
};