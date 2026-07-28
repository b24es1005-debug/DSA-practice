class Solution {
public:
    int countPartitions(vector<int>& arr, int diff) {
        // GFG asks for the answer modulo 1e9+7
        const int MOD = 1e9 + 7;
        // ------------------------------------------------------------
        // Problem:
        // Count the number of ways to partition the array into
        // two subsets such that:
        // |S1 - S2| = diff
        // Let totalSum = S1 + S2
        // Then,
        // S2 = (totalSum - diff) / 2
        // So the problem becomes:
        // Count subsets having sum = target.
        // ------------------------------------------------------------
        int totalSum = 0;
        for (int x : arr)
            totalSum += x;
        // Impossible cases:
        // 1. diff is larger than total sum.
        // 2. (totalSum - diff) must be even.
        if (totalSum < diff || (totalSum - diff) % 2 != 0)
            return 0;
        int target = (totalSum - diff) / 2;
        // dp[sum] = Number of ways to make 'sum'
        vector<int> dp(target + 1, 0);
        // One way to make sum 0:
        // choose the empty subset.
        dp[0] = 1;
        for (int x : arr) {
            // Special handling for zero:
            // Every existing subset can either include
            // or exclude this zero.
            if (x == 0) {
                for (int sum = 0; sum <= target; sum++)
                    dp[sum] = (2LL * dp[sum]) % MOD;
            }
            else {
                // Traverse backwards so that each element
                // is used only once (0/1 Knapsack).
                for (int sum = target; sum >= x; sum--) {
                    dp[sum] =
                        (dp[sum] + dp[sum - x]) % MOD;
                }
            }
        }

        return dp[target];
    }
};