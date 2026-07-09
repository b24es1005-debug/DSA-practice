// ================================================================
// LEETCODE 120 - Triangle (Minimum Path Sum in Triangle)
// ================================================================

class Solution {
public:
    // TYPE 1: Bottom-Up DP
    // T.C: O(n²), S.C: O(n²)
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base: Last row
        for (int j = 0; j < n; j++) {
            dp[n-1][j] = triangle[n-1][j];
        }
        
        // Fill from bottom to top
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                // Can go to (i+1, j) or (i+1, j+1)
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
    }
    
    // TYPE 2: Space Optimized (1D DP)
    // T.C: O(n²), S.C: O(n)
    int minimumTotalOptimized(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n-1];  // Start with last row
        
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        
        return dp[0];
    }
};

// ================================================================
// LEETCODE 931 - Minimum Falling Path Sum
// ================================================================

class Solution {
public:
    // TYPE 1: 2D DP
    // T.C: O(n²), S.C: O(n²)
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        // Base: First row
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        
        // For each subsequent row
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Can come from: (i-1, j-1), (i-1, j), (i-1, j+1)
                int fromAbove = dp[i-1][j];
                int fromLeftDiag = (j > 0) ? dp[i-1][j-1] : INT_MAX;
                int fromRightDiag = (j < n-1) ? dp[i-1][j+1] : INT_MAX;
                
                dp[i][j] = matrix[i][j] + min({fromAbove, fromLeftDiag, fromRightDiag});
            }
        }
        
        // Find minimum in last row
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
    
    // TYPE 2: Space Optimized
    // T.C: O(n²), S.C: O(n)
    int minFallingPathSumOptimized(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp = matrix[0];  // First row
        
        for (int i = 1; i < n; i++) {
            vector<int> newDp(n, 0);
            for (int j = 0; j < n; j++) {
                int fromAbove = dp[j];
                int fromLeftDiag = (j > 0) ? dp[j-1] : INT_MAX;
                int fromRightDiag = (j < n-1) ? dp[j+1] : INT_MAX;
                
                newDp[j] = matrix[i][j] + min({fromAbove, fromLeftDiag, fromRightDiag});
            }
            dp = newDp;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};