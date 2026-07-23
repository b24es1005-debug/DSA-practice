class Solution {//2D DP Memoization Top down
private://TC: O(nXamount) SC: O(nXamount)
    int solve(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // Base Case: Reached exact amount
        if (amount == 0) return 0;
        // Base Case: No coins left
        if (idx < 0) return INT_MAX - 1;
        // Check if already computed
        if (dp[idx][amount] != -1) return dp[idx][amount];
        // Option 1: Skip current coin
        int notTake = solve(idx - 1, amount, coins, dp);
        // Option 2: Take current coin (unlimited supply)
        int take = INT_MAX;
        if (amount >= coins[idx]) {
            take = 1 + solve(idx, amount - coins[idx], coins, dp);
        }
        // Store and return result
        return dp[idx][amount] = min(notTake, take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n - 1, amount, coins, dp);
        return ans >= INT_MAX - 1 ? -1 : ans;
    }
};

class Solution {//1D DP Space optimised
private://TC: O(nXamount) SC: S(n)
    // Recursive function to find minimum coins
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        // Base case 1: Perfect! We've made the exact amount
        if (amount == 0) return 0;
        // Base case 2: Overshot! This path is invalid
        if (amount < 0) return 1e9;  // Return "infinity"        
        // Check memoization: Already solved this amount?
        if (dp[amount] != -1) return dp[amount];
        // Try all coins to find the best combination
        int minCoins = 1e9;  // Start with infinity
        for (int coin : coins) {
            // Use this coin: 1 + recursively solve remaining amount
            int current = 1 + solve(coins, amount - coin, dp);
            minCoins = min(minCoins, current);
        }
        // Store the result in dp array and return it
        return dp[amount] = minCoins;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // Initialize dp with -1 (meaning "not computed yet")
        vector<int> dp(amount + 1, -1);
        // Get answer
        int ans = solve(coins, amount, dp);
        // If answer is still infinity, it's impossible
        return (ans != 1e9) ? ans : -1;
    }
};