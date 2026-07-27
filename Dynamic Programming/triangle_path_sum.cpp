class Solution {//TC: O(NXN) SC: S(NXN)
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Create 2D DP table with same dimensions as triangle
        vector<vector<int>> dp(n);
        // Initialize each row with appropriate size
        for(int i = 0; i < n; i++) {
            dp[i].resize(i + 1);
        }
        // Base case: bottom row
        for(int j = 0; j < n; j++) {
            dp[n-1][j] = triangle[n-1][j];
        }
        // Bottom-up DP
        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};


class Solution{//space optimised S(N)
public:
    int triagleMinSum(vector<vector<int>>& tringle){
        int n = triangle.size();
        vector<int> dp = triangle[n-1];
        for(int i = n-2;i>=0;i--){
            for(int j = 0;j<=i;j++){
                dp[j] = triangle[i][j] + min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }

};