class Solution {//recursive
  private:
    bool f(int idx, int target, vector<int>& arr) {
        // If target becomes 0, we found a subset
        if (target == 0) return true;
        // If no elements left or target becomes negative
        if (idx < 0) return false;
        // Don't pick current element
        bool notpick = f(idx - 1, target, arr);
        // Pick current element (only if possible)
        bool pick = false;
        if (target >= arr[idx]) {
            pick = f(idx - 1, target - arr[idx], arr);
        }
        return pick || notpick;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // Edge cases
        if (sum == 0) return true;
        if (arr.empty()) return false;
        return f(arr.size() - 1, sum, arr);
    }
};

class Solution {//memoization
  private:
    bool f(int idx, int target, vector<int>& arr, vector<vector<int>>& dp) {
        // Base case: found a subset
        if (target == 0) return true;
        
        // No elements left to consider
        if (idx < 0) return false;
        
        // Check if already computed
        if (dp[idx][target] != -1) return dp[idx][target];
        
        // Option 1: Don't pick current element
        bool notpick = f(idx - 1, target, arr, dp);
        
        // Option 2: Pick current element (only if possible)
        bool pick = false;
        if (target >= arr[idx]) {
            pick = f(idx - 1, target - arr[idx], arr, dp);
        }
        
        // Store and return result
        return dp[idx][target] = pick || notpick;
    }
    
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // Edge cases
        if (sum == 0) return true;
        if (arr.empty()) return false;
        
        int n = arr.size();
        // dp[i][j] = -1 (not computed), 0 (false), 1 (true)
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        
        return f(n - 1, sum, arr, dp);
    }
};

class Solution {//Tabulation Space optimised 1D DP
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        if (sum == 0) return true;
        if (arr.empty()) return false;
        
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        
        for (int x : arr) {
            // Process backwards to avoid reusing same element
            for (int j = sum; j >= x; j--) {
                dp[j] = dp[j] || dp[j - x];
            }
        }
        
        return dp[sum];
    }
};