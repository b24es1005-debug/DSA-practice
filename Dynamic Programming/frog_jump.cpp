// ================================================================
// PROBLEM: Frog Jump (Frog at step 0, can jump 1 or 2 steps)
// Find minimum energy to reach step n-1
// Energy cost: |height[i] - height[i-1]| when jumping from i-1 to i
// ================================================================

// ================================================================
// TYPE 1: MEMOIZATION (Top-Down DP)
// Time Complexity: O(n) - Each state computed once
// Space Complexity: O(n) - Recursion stack + memo array
// ================================================================

// ================================================================
// UNDERSTANDING THE RECURRENCE:
// ================================================================
// dp[i] = minimum energy to reach step i
// dp[i] = min(
//     dp[i-1] + |height[i] - height[i-1]|,  // Jump 1 step
//     dp[i-2] + |height[i] - height[i-2]|   // Jump 2 steps
// )
// 
// Base cases:
// dp[0] = 0  (Already at start)
// dp[1] = |height[1] - height[0]|  (Only 1 way to reach step 1)
// ================================================================

// ================================================================
// WHEN TO USE EACH APPROACH:
// ================================================================
// 1. Memoization: When only some states are needed or problem has 
//                  complex dependencies
// 2. Tabulation: When all states need to be computed (cleaner)
// 3. Space Optimized: When memory is constrained (preferred)
// 4. K-step Tab: When k is small and you need clarity
// 5. K-step Optimized: When k is moderate and memory matters
// 6. K-step Deque: When k is large and O(n*k) is too slow
// ================================================================

#include <bits/stdc++.h>
using namespace std;

class Memoization {
private:
    vector<int> memo;
    vector<int> height;
    
    int solve(int n) {
        // Base case: If at step 0, no energy needed
        // T.C: O(n) - Each state computed once
        // S.C: O(n) - Recursion call stack + memo array
        if (n == 0) return 0;
        
        // If already computed, return stored value
        if (memo[n] != -1) return memo[n];
        
        // Option 1: Jump from n-1 to n (1 step)
        int jump1 = solve(n - 1) + abs(height[n] - height[n - 1]);
        
        // Option 2: Jump from n-2 to n (2 steps)
        int jump2 = INT_MAX;
        if (n >= 2) {
            jump2 = solve(n - 2) + abs(height[n] - height[n - 2]);
        }
        
        // Store and return minimum energy
        return memo[n] = min(jump1, jump2);
    }
    
public:
    int frogJump(vector<int>& heights) {
        height = heights;
        int n = height.size();
        memo.resize(n, -1);
        return solve(n - 1);  // Start from last step
    }
};

// ================================================================
// TYPE 2: TABULATION (Bottom-Up DP)
// Time Complexity: O(n) - Single loop from 0 to n-1
// Space Complexity: O(n) - DP array of size n
// ================================================================

class Tabulation {
public:
    int frogJump(vector<int>& height) {
        int n = height.size();
        
        // DP table to store minimum energy to reach each step
        // T.C: O(n) - Fill array from bottom to top
        // S.C: O(n) - Array of size n
        vector<int> dp(n, 0);
        
        // Base case: Starting at step 0 requires 0 energy
        dp[0] = 0;
        
        // If only 1 step, we're already there
        if (n == 1) return 0;
        
        // For step 1, only possible from step 0
        dp[1] = abs(height[1] - height[0]);
        
        // Fill the DP table from step 2 to n-1
        for (int i = 2; i < n; i++) {
            // Jump from i-1 to i (1 step)
            int jump1 = dp[i - 1] + abs(height[i] - height[i - 1]);
            
            // Jump from i-2 to i (2 steps)
            int jump2 = dp[i - 2] + abs(height[i] - height[i - 2]);
            
            // Take minimum of both options
            dp[i] = min(jump1, jump2);
        }
        
        return dp[n - 1];
    }
};

// ================================================================
// TYPE 3: SPACE OPTIMIZED (Constant Space)
// Time Complexity: O(n) - Single pass from 0 to n-1
// Space Complexity: O(1) - Only 3 variables used
// ================================================================

class SpaceOptimized {
public:
    int frogJump(vector<int>& height) {
        int n = height.size();
        
        // Base case: Only 1 step
        // T.C: O(n) - Iterate n times
        // S.C: O(1) - Constant extra space
        if (n == 1) return 0;
        
        // Only maintain last two computed values
        int prev2 = 0;  // dp[i-2] - Minimum energy to reach step i-2
        int prev1 = abs(height[1] - height[0]);  // dp[i-1] - Minimum energy to reach step i-1
        int curr;
        
        // Start from step 2
        for (int i = 2; i < n; i++) {
            // Jump from i-1 to i (1 step)
            int jump1 = prev1 + abs(height[i] - height[i - 1]);
            
            // Jump from i-2 to i (2 steps)
            int jump2 = prev2 + abs(height[i] - height[i - 2]);
            
            // Current minimum energy to reach step i
            curr = min(jump1, jump2);
            
            // Shift values for next iteration
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};

// ================================================================
// VARIATION: FROG JUMP WITH K STEPS (Can jump 1 to k steps)
// ================================================================

class FrogJumpKSteps {
private:
    vector<int> memo;
    vector<int> height;
    int k;
    
    // TYPE 1: Memoization for K steps
    int solveK(int n) {
        // T.C: O(n*k) - Each state checks k options
        // S.C: O(n) - Memo array + recursion stack
        if (n == 0) return 0;
        if (memo[n] != -1) return memo[n];
        
        int minEnergy = INT_MAX;
        
        // Try jumping 1 to k steps back
        for (int jump = 1; jump <= k && n - jump >= 0; jump++) {
            int energy = solveK(n - jump) + abs(height[n] - height[n - jump]);
            minEnergy = min(minEnergy, energy);
        }
        
        return memo[n] = minEnergy;
    }
    
public:
    // TYPE 2: Tabulation for K steps
    int frogJumpKTab(vector<int>& heights, int kSteps) {
        // T.C: O(n*k) - For each position, try k jumps
        // S.C: O(n) - DP array
        height = heights;
        k = kSteps;
        int n = height.size();
        
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i < n; i++) {
            for (int jump = 1; jump <= k && i - jump >= 0; jump++) {
                int energy = dp[i - jump] + abs(height[i] - height[i - jump]);
                dp[i] = min(dp[i], energy);
            }
        }
        
        return dp[n - 1];
    }
    
    // TYPE 3: Space Optimized for K steps (using sliding window)
    int frogJumpKOptimized(vector<int>& heights, int kSteps) {
        // T.C: O(n*k) - Still need to check k jumps
        // S.C: O(k) - Need last k results
        int n = heights.size();
        if (n == 1) return 0;
        
        vector<int> dp(kSteps + 1, 0);
        dp[0] = 0;  // dp[0] represents current position
        dp[1] = abs(heights[1] - heights[0]);  // Jump 1 step
        
        for (int i = 2; i < n; i++) {
            int curr = INT_MAX;
            for (int jump = 1; jump <= kSteps && i - jump >= 0; jump++) {
                int idx = jump % (kSteps + 1);
                int energy = dp[idx] + abs(heights[i] - heights[i - jump]);
                curr = min(curr, energy);
            }
            dp[i % (kSteps + 1)] = curr;
        }
        
        return dp[(n - 1) % (kSteps + 1)];
    }
};

// ================================================================
// VARIATION: FROG JUMP WITH K STEPS (Using Deque - O(n) optimized)
// ================================================================

class FrogJumpOptimizedK {
public:
    int frogJumpKDeque(vector<int>& height, int k) {
        // T.C: O(n) - Each element pushed/popped once
        // S.C: O(k) - Deque stores at most k elements
        int n = height.size();
        if (n == 1) return 0;
        
        vector<int> dp(n, 0);
        deque<int> dq;  // Stores indices with increasing dp values
        
        dp[0] = 0;
        dq.push_back(0);
        
        for (int i = 1; i < n; i++) {
            // Remove indices outside window of size k
            while (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }
            
            // Calculate dp[i] using minimum in window
            int minIdx = dq.front();
            dp[i] = dp[minIdx] + abs(height[i] - height[minIdx]);
            
            // Maintain deque in increasing order of dp values
            while (!dq.empty() && dp[dq.back()] >= dp[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        return dp[n - 1];
    }
};

// ================================================================
// DRIVER CODE TO TEST ALL TYPES
// ================================================================

int main() {
    // Test Case 1: Basic Frog Jump (1 or 2 steps)
    vector<int> height1 = {10, 30, 40, 20};
    // Expected output: 30 (10->40->20 or 10->30->20)
    
    Memoization memo;
    Tabulation tab;
    SpaceOptimized space;
    
    cout << "Test Case 1: Heights [10, 30, 40, 20]\n";
    cout << "Memoization: " << memo.frogJump(height1) << endl;
    cout << "Tabulation: " << tab.frogJump(height1) << endl;
    cout << "Space Optimized: " << space.frogJump(height1) << endl;
    cout << endl;
    
    // Test Case 2: Another example
    vector<int> height2 = {10, 20, 30, 10};
    // Expected output: 20 (10->30->10)
    
    cout << "Test Case 2: Heights [10, 20, 30, 10]\n";
    cout << "Memoization: " << memo.frogJump(height2) << endl;
    cout << "Tabulation: " << tab.frogJump(height2) << endl;
    cout << "Space Optimized: " << space.frogJump(height2) << endl;
    cout << endl;
    
    // Test Case 3: Frog Jump with K steps
    vector<int> height3 = {10, 30, 40, 50, 20};
    int k = 3;
    FrogJumpKSteps frogK;
    
    cout << "Test Case 3: K steps (k=3)\n";
    cout << "K-step Tabulation: " << frogK.frogJumpKTab(height3, k) << endl;
    cout << endl;
    
    // Test Case 4: Optimized K steps with Deque
    FrogJumpOptimizedK frogKOpt;
    cout << "Test Case 4: K steps optimized (k=3)\n";
    cout << "K-step Optimized: " << frogKOpt.frogJumpKDeque(height3, k) << endl;
    
    return 0;
}

// ================================================================
// SUMMARY OF ALL APPROACHES:
// ================================================================
// | Approach          | Time Complexity | Space Complexity |
// |-------------------|-----------------|------------------|
// | 1. Memoization    | O(n)            | O(n)             |
// | 2. Tabulation     | O(n)            | O(n)             |
// | 3. Space Optimized| O(n)            | O(1)             |
// | 4. K-step Tab     | O(n*k)          | O(n)             |
// | 5. K-step Opt     | O(n*k)          | O(k)             |
// | 6. K-step Deque   | O(n)            | O(k)             |
// ================================================================

