class Solution {// S1 = elements assigned '+'
        // S2 = elements assigned '-'
        // S1 - S2 = target
        // S1 + S2 = totalSum
        // => S2 = (totalSum - target) / 2
        // So the problem reduces to:
        // Count the number of subsets having sum = S2.
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int x : nums)
            totalSum += x;
        // Impossible cases:
        // 1. Target is outside the achievable range [-totalSum, totalSum].
        // 2. (totalSum - target) must be even.
        if (abs(target) > totalSum || (totalSum - target) % 2 != 0)
            return 0;
        int reqSum = (totalSum - target) / 2;
        // dp[sum] = Number of ways to make 'sum'
        vector<int> dp(reqSum + 1, 0);
        // One way to make sum 0:
        // choose the empty subset.
        dp[0] = 1;
        for (int x : nums) {
            // Zero can either be picked or not picked
            // without changing the sum.
            if (x == 0) {
                for (int sum = 0; sum <= reqSum; sum++)
                    dp[sum] *= 2;//either be picked or not picked. {0} {}
            }
            else {
                // Traverse backwards so that each number
                // is used only once (0/1 Knapsack).
                for (int sum = reqSum; sum >= x; sum--) {
                    dp[sum] += dp[sum - x];
                }
            }
        }
        return dp[reqSum];
    }
};