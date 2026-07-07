// ================================================================
// TYPE 1: MEMOIZATION (Top-Down DP)
// Time Complexity: O(n) - Each Fibonacci number computed once
// Space Complexity: O(n) - Recursion stack + memo array
// ================================================================

#include <bits/stdc++.h>
using namespace std;

class Memoization {
private:
    // Memoization array to store computed Fibonacci numbers
    // -1 indicates value not computed yet
    vector<long long> memo;
    
    long long fibHelper(int n) {
        // Base cases
        if (n <= 1) return n;
        
        // If already computed, return stored value
        if (memo[n] != -1) return memo[n];
        
        // Recursively compute and store result
        // T.C: O(n) - Each state computed once
        // S.C: O(n) - Recursion call stack depth
        return memo[n] = fibHelper(n - 1) + fibHelper(n - 2);
    }
    
public:
    long long fib(int n) {
        // Initialize memo with -1
        memo.resize(n + 1, -1);
        return fibHelper(n);
    }
};

// ================================================================
// TYPE 2: TABULATION (Bottom-Up DP)
// Time Complexity: O(n) - Single loop from 0 to n
// Space Complexity: O(n) - DP array of size n+1
// ================================================================

class Tabulation {
public:
    long long fib(int n) {
        // Handle base cases
        if (n <= 1) return n;
        
        // DP table to store computed values
        // T.C: O(n) - Fill array from bottom to top
        // S.C: O(n) - Array of size n+1
        vector<long long> dp(n + 1, 0);
        
        // Base cases initialization
        dp[0] = 0;
        dp[1] = 1;
        
        // Fill the DP table iteratively
        // Each state depends on previous two states
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};

// ================================================================
// TYPE 3: SPACE OPTIMIZED (Constant Space)
// Time Complexity: O(n) - Single pass from 0 to n
// Space Complexity: O(1) - Only 3 variables used
// ================================================================

class SpaceOptimized {
public:
    long long fib(int n) {
        // Handle base cases
        if (n <= 1) return n;
        
        // Only maintain last two Fibonacci numbers
        // T.C: O(n) - Iterate n times
        // S.C: O(1) - Constant extra space
        long long prev2 = 0;  // F(0)
        long long prev1 = 1;  // F(1)
        long long curr;
        
        // Iterate from 2 to n
        for (int i = 2; i <= n; i++) {
            // Current Fibonacci = sum of previous two
            curr = prev1 + prev2;
            
            // Shift values for next iteration
            prev2 = prev1;
            prev1 = curr;
        }
        
        return curr;
    }
};

// ================================================================
// ALTERNATIVE: SPACE OPTIMIZED with Rolling Array (Bonus)
// Time Complexity: O(n)
// Space Complexity: O(1) using rolling array technique
// ================================================================

class RollingArray {
public:
    long long fib(int n) {
        if (n <= 1) return n;
        
        // Using 2-sized array as rolling window
        // T.C: O(n) 
        // S.C: O(1) - Fixed array size 2
        long long dp[2] = {0, 1};
        
        for (int i = 2; i <= n; i++) {
            // Compute new value using modulo indexing
            long long curr = dp[0] + dp[1];
            
            // Roll the window
            dp[0] = dp[1];
            dp[1] = curr;
        }
        
        return dp[1];
    }
};

// ================================================================
// DRIVER CODE TO TEST ALL TYPES
// ================================================================

int main() {
    int n = 10; // Test with n = 10 (Fibonacci: 55)
    
    // Type 1: Memoization
    Memoization memo;
    cout << "Memoization: " << memo.fib(n) << endl;
    
    // Type 2: Tabulation
    Tabulation tab;
    cout << "Tabulation: " << tab.fib(n) << endl;
    
    // Type 3: Space Optimized
    SpaceOptimized space;
    cout << "Space Optimized: " << space.fib(n) << endl;
    
    // Bonus: Rolling Array
    RollingArray rolling;
    cout << "Rolling Array: " << rolling.fib(n) << endl;
    
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
// | 4. Rolling Array  | O(n)            | O(1)             |
// ================================================================

// Key differences:
// - Memoization: Recursive, top-down, uses call stack
// - Tabulation: Iterative, bottom-up, uses DP table
// - Space Optimized: Most efficient, only keeps needed values
// - Rolling Array: Alternative O(1) space with fixed array

// When to use:
// - Memoization: When only some states are needed (e.g., with pruning)
// - Tabulation: When all states are needed (simpler to implement)
// - Space Optimized: When memory is constrained (preferred for Fibonacci)