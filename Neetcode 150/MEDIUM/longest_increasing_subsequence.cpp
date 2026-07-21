class Solution {//Memoization DP
private:
    int f(int idx, int prev_idx, vector<int>& nums, int n, vector<vector<int>>& dp) {
        if (idx == n) return 0;
        if (dp[idx][prev_idx + 1] != -1) return dp[idx][prev_idx + 1];
        
        // Option 1: Don't take current element
        int len = f(idx + 1, prev_idx, nums, n, dp);
        
        // Option 2: Take current element if it's greater than previous
        if (prev_idx == -1 || nums[idx] > nums[prev_idx]) {
            len = max(len, 1 + f(idx + 1, idx, nums, n, dp));
        }
        
        return dp[idx][prev_idx + 1] = len;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();  // Define n here
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, n, dp);
    }
};

class Solution {//Patience Sorting
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) {
                tails.push_back(num);
            } else {
                *it = num;
            }
        }
        return tails.size();
    }
};