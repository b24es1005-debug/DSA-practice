class Solution {//Memoization O(nXn)
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

class Solution {//TABULATION: Iterative Solution
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> dp(n, 1);  // dp[i] = LIS ending at index i
        int maxLen = 1;
        
        for (int i = 1; i < n; i++) {//for each position i 
            for (int j = 0; j < i; j++) {//check all previous position j
                if (nums[i] > nums[j]) {//satisfying the LIS
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        
        return maxLen;
    }
};

class Solution {//Patience Sorting (O(n log n))
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