// ================================================================
// HOUSE ROBBER PROBLEM
// Problem: You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money. Adjacent houses have security systems
// connected, so you cannot rob two adjacent houses.
// Find the maximum amount you can rob tonight.
// ================================================================

#include <bits/stdc++.h>
using namespace std;

// ================================================================
// TYPE 1: PURE RECURSION (Brute Force)
// Time Complexity: O(2^n) - Exponential, tries all combinations
// Space Complexity: O(n) - Recursion stack depth
// ================================================================

class Solution1 {
private:
    // Recursive function to find max money from idx to end
    // T.C: O(2^n), S.C: O(n)
    int f(int idx, vector<int>& nums) {
        // Base case: If at first house, must rob it
        if (idx == 0) return nums[idx];
        
        // Base case: If no houses left
        if (idx < 0) return 0;
        
        // Option 1: Rob current house, skip adjacent (idx-1), go to idx-2
        int pick = nums[idx] + f(idx - 2, nums);
        
        // Option 2: Don't rob current house, move to next (idx-1)
        int notpick = 0 + f(idx - 1, nums);
        
        // Return maximum of both options
        return max(pick, notpick);
    }
    
public:
    int rob(vector<int>& nums) {
        // Start from last house
        return f(nums.size() - 1, nums);
    }
};

// ================================================================
// TYPE 2: MEMOIZATION (Top-Down DP)
// Time Complexity: O(n) - Each state computed once
// Space Complexity: O(n) - DP array + recursion stack
// ================================================================

class Solution2 {
private:
    // Recursive function with memoization
    // T.C: O(n), S.C: O(n)
    int f(int idx, vector<int>& nums, vector<int>& dp) {
        // Base case: At first house, must rob it
        if (idx == 0) return nums[idx];
        
        // Base case: No houses left
        if (idx < 0) return 0;
        
        // If already computed, return stored value
        if (dp[idx] != -1) return dp[idx];
        
        // Option 1: Rob current house + rob houses till idx-2
        int pick = nums[idx] + f(idx - 2, nums, dp);
        
        // Option 2: Skip current house + rob houses till idx-1
        int notpick = 0 + f(idx - 1, nums, dp);
        
        // Store and return maximum
        return dp[idx] = max(pick, notpick);
    }
    
public:
    int rob(vector<int>& nums) {
        // Initialize memo array with -1
        vector<int> dp(nums.size(), -1);
        return f(nums.size() - 1, nums, dp);
    }
};

// ================================================================
// TYPE 3: TABULATION (Bottom-Up DP)
// Time Complexity: O(n) - Single loop
// Space Complexity: O(n) - DP array
// ================================================================

class Solution3 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Edge case: If only 1 house
        if (n == 1) return nums[0];
        
        // DP array to store max money till each house
        // T.C: O(n), S.C: O(n)
        vector<int> dp(n, 0);
        
        // Base cases
        dp[0] = nums[0];  // With only 1 house, rob it
        
        // For 2 houses, rob the one with more money
        dp[1] = max(nums[0], nums[1]);
        
        // Fill DP table from house 2 to n-1
        for (int i = 2; i < n; i++) {
            // Option 1: Rob current house + max money till i-2
            int pick = nums[i] + dp[i - 2];
            
            // Option 2: Skip current house, take max money till i-1
            int notpick = dp[i - 1];
            
            // Take maximum of both options
            dp[i] = max(pick, notpick);
        }
        
        return dp[n - 1];
    }
};

// ================================================================
// TYPE 4: SPACE OPTIMIZED (Constant Space) - MOST EFFICIENT
// Time Complexity: O(n) - Single pass
// Space Complexity: O(1) - Only 3 variables
// ================================================================

class Solution4 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases
        // T.C: O(n), S.C: O(1)
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // We only need last two values
        int prev2 = nums[0];        // dp[i-2] - Max money till i-2
        int prev1 = max(nums[0], nums[1]);  // dp[i-1] - Max money till i-1
        int curr = 0;
        
        // Start from house 2
        for (int i = 2; i < n; i++) {
            // Option 1: Rob current house + max till i-2
            int pick = nums[i] + prev2;
            
            // Option 2: Skip current house, take max till i-1
            int notpick = prev1;
            
            // Current max = max of both options
            curr = max(pick, notpick);
            
            // Shift values for next iteration
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;  // Max money till last house
    }
};

// ================================================================
// ALTERNATIVE SPACE OPTIMIZED (Using 2 variables)
// Time Complexity: O(n)
// Space Complexity: O(1)
// ================================================================

class Solution5 {
public:
    int rob(vector<int>& nums) {
        // T.C: O(n), S.C: O(1)
        int rob = 0;      // Max money if we rob current house
        int notRob = 0;   // Max money if we don't rob current house
        
        for (int i = 0; i < nums.size(); i++) {
            // New value if we rob current house
            int newRob = notRob + nums[i];
            
            // New value if we don't rob current house
            int newNotRob = max(rob, notRob);
            
            // Update for next iteration
            rob = newRob;
            notRob = newNotRob;
        }
        
        return max(rob, notRob);
    }
};

// ================================================================
// VARIATION: HOUSE ROBBER II (Circular Houses)
// Houses are arranged in a circle, first and last are adjacent
// Time Complexity: O(n)
// Space Complexity: O(1)
// ================================================================

class SolutionCircular {
private:
    // Helper function for linear house robber
    int robLinear(vector<int>& nums, int start, int end) {
        // T.C: O(n), S.C: O(1)
        int prev2 = 0;  // dp[i-2]
        int prev1 = 0;  // dp[i-1]
        
        for (int i = start; i <= end; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // Two cases:
        // 1. Rob houses from 0 to n-2 (exclude last)
        // 2. Rob houses from 1 to n-1 (exclude first)
        // Take maximum of both
        return max(robLinear(nums, 0, n-2), robLinear(nums, 1, n-1));
    }
};

// ================================================================
// VARIATION: HOUSE ROBBER III (Binary Tree Houses)
// Houses are arranged in a binary tree
// Time Complexity: O(n)
// Space Complexity: O(h) where h is height of tree
// ================================================================

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class SolutionTree {
private:
    // Returns pair<int, int>: {max with current node, max without current node}
    // T.C: O(n), S.C: O(h)
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        
        // Get results from left and right subtrees
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        
        // If we rob current node, we cannot rob its children
        int rob = root->val + left.second + right.second;
        
        // If we don't rob current node, we can rob or not rob children
        int notRob = max(left.first, left.second) + max(right.first, right.second);
        
        return {rob, notRob};
    }
    
public:
    int rob(TreeNode* root) {
        pair<int, int> result = dfs(root);
        return max(result.first, result.second);
    }
};

// ================================================================
// DRIVER CODE TO TEST ALL SOLUTIONS
// ================================================================

int main() {
    // Test Case 1: [1,2,3,1] -> Expected: 4 (rob house 1 and 3: 1+3=4)
    vector<int> nums1 = {1, 2, 3, 1};
    
    cout << "Test Case 1: [1,2,3,1]" << endl;
    
    Solution1 s1;
    cout << "Pure Recursion: " << s1.rob(nums1) << endl;
    
    Solution2 s2;
    cout << "Memoization: " << s2.rob(nums1) << endl;
    
    Solution3 s3;
    cout << "Tabulation: " << s3.rob(nums1) << endl;
    
    Solution4 s4;
    cout << "Space Optimized: " << s4.rob(nums1) << endl;
    
    Solution5 s5;
    cout << "Alternative Space Opt: " << s5.rob(nums1) << endl;
    cout << endl;
    
    // Test Case 2: [2,7,9,3,1] -> Expected: 12 (rob house 1,3,5: 2+9+1=12)
    vector<int> nums2 = {2, 7, 9, 3, 1};
    
    cout << "Test Case 2: [2,7,9,3,1]" << endl;
    cout << "Space Optimized: " << s4.rob(nums2) << endl;
    cout << endl;
    
    // Test Case 3: Circular houses
    vector<int> nums3 = {2, 3, 2};  // Expected: 3 (can't rob both 2's as they're adjacent)
    SolutionCircular sc;
    cout << "Circular Houses [2,3,2]: " << sc.rob(nums3) << endl;
    
    return 0;
}

// ================================================================
// SUMMARY OF ALL APPROACHES:
// ================================================================
// | Approach          | Time Complexity | Space Complexity | When to Use |
// |-------------------|-----------------|------------------|-------------|
// | 1. Pure Recursion | O(2^n)          | O(n)             | Never (too slow) |
// | 2. Memoization    | O(n)            | O(n)             | When top-down is intuitive |
// | 3. Tabulation     | O(n)            | O(n)             | When you need all states |
// | 4. Space Optimized| O(n)            | O(1)             | ✅ PREFERRED |
// | 5. Alt Space Opt  | O(n)            | O(1)             | Alternative O(1) approach |
// | 6. Circular       | O(n)            | O(1)             | When houses are in circle |
// | 7. Tree           | O(n)            | O(h)             | When houses are in tree |
// ================================================================

// ================================================================
// KEY INSIGHTS FOR HOUSE ROBBER:
// ================================================================
// 1. Recurrence Relation:
//    dp[i] = max(nums[i] + dp[i-2], dp[i-1])
//    
// 2. Base Cases:
//    dp[0] = nums[0]
//    dp[1] = max(nums[0], nums[1])
//    
// 3. The problem is essentially finding max sum of non-adjacent elements
//    
// 4. Space optimization works because each state only depends on 
//    previous two states (dp[i-1] and dp[i-2])
//    
// 5. For circular houses, break the circle by considering two cases:
//    - Include first house, exclude last
//    - Exclude first house, include last
// ================================================================