// ================================================================
// LEETCODE 64 - Minimum Path Sum
// ================================================================

class Solution {
public:
    // TYPE 1: 2D DP
    // T.C: O(m*n), S.C: O(m*n)
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Base case: Start position
        dp[0][0] = grid[0][0];
        
        // Fill first row (can only come from left)
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        // Fill first column (can only come from above)
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        // Fill the rest
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // Take minimum of coming from above or left
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[m-1][n-1];
    }
    
    // TYPE 2: Space Optimized (1D DP)
    // T.C: O(m*n), S.C: O(n)
    int minPathSumOptimized(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> dp(n, 0);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[j] = grid[0][0];
                } else if (i == 0) {
                    dp[j] = dp[j-1] + grid[i][j];
                } else if (j == 0) {
                    dp[j] = dp[j] + grid[i][j];
                } else {
                    dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
                }
            }
        }
        
        return dp[n-1];
    }
    
    // TYPE 3: In-place DP (Modifying original grid)
    // T.C: O(m*n), S.C: O(1)
    int minPathSumInPlace(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Modify grid in place
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (i == 0) {
                    grid[i][j] += grid[i][j-1];
                } else if (j == 0) {
                    grid[i][j] += grid[i-1][j];
                } else {
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                }
            }
        }
        
        return grid[m-1][n-1];
    }
};