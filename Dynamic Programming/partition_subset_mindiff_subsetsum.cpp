class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        
        // Edge case: empty array or single element
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int totalSum = 0;
        for (int x : nums) {
            totalSum += x;
        }
        
        int k = totalSum;
        
        // dp[i][j] = possible to get sum j using first i+1 elements
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
        
        // Base case: sum 0 is always possible
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        
        // Base case: first element
        if (nums[0] <= k) {
            dp[0][nums[0]] = true;
        }
        
        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                // Don't pick current element
                bool notpick = dp[i-1][j];
                
                // Pick current element (if possible)
                bool pick = false;
                if (j >= nums[i]) {
                    pick = dp[i-1][j - nums[i]];
                }
                
                dp[i][j] = pick || notpick;
            }
        }
        
        // Find minimum difference
        int mini = INT_MAX;
        for (int s1 = 0; s1 <= totalSum / 2; s1++) {
            if (dp[n-1][s1]) {
                int s2 = totalSum - s1;
                mini = min(mini, abs(s2 - s1));
            }
        }
        
        return mini;
    }
};

class Solution {//space optimised 1D dp
public:
    int minimumDifference(vector<int>& nums) {
        int totalSum = 0;
        for (int x : nums) {
            totalSum += x;
        }
        
        vector<bool> dp(totalSum + 1, false);
        dp[0] = true;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = totalSum; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        
        int mini = INT_MAX;
        for (int s1 = 0; s1 <= totalSum / 2; s1++) {
            if (dp[s1]) {
                int s2 = totalSum - s1;
                mini = min(mini, abs(s2 - s1));
            }
        }
        
        return mini;
    }
};