class Solution {//2D DP
public:
    int perfectSum(vector<int>& arr, int target) {

        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {

            for (int sum = 0; sum <= target; sum++) {

                dp[i][sum] = dp[i - 1][sum];

                if (arr[i - 1] <= sum)
                    dp[i][sum] += dp[i - 1][sum - arr[i - 1]];
            }
        }

        return dp[n][target];
    }
};

class Solution {//1D DP
public:
    int perfectSum(vector<int>& arr, int target) {

        vector<int> dp(target + 1, 0);

        dp[0] = 1;

        for (int x : arr) {

            if (x == 0) {
                for (int sum = 0; sum <= target; sum++)
                    dp[sum] *= 2;
            }
            else {
                for (int sum = target; sum >= x; sum--)
                    dp[sum] += dp[sum - x];
            }
        }

        return dp[target];
    }
};