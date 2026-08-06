class Solution {
public:
    vector<string> ans;  // Stores all valid parentheses combinations
    /**
     * Recursive backtracking function to generate valid parentheses
     * param curr: Current string being built
     * param open: Number of '(' used so far
     * param close: Number of ')' used so far  
     * param n: Total number of pairs needed
     */
    void generate(string& curr, int open, int close, int n) {
        // Base case: If we've used all n pairs (2n characters total)
        if(curr.size() == 2 * n) {
            ans.push_back(curr);  // Current string is a valid combination
            return;  // Exit this recursive path
        }
        // Choice 1: Add an opening bracket '(' if possible
        if(open < n) {
            curr.push_back('(');           // Add '(' to current string
            generate(curr, open + 1, close, n);  // Recurse with updated open count
            curr.pop_back();               // Backtrack: remove the '(' we added
        }
        // Choice 2: Add a closing bracket ')' if valid
        // Condition ensures we never have more ')' than '(' in the prefix
        if(open > close) {
            curr.push_back(')');           // Add ')' to current string
            generate(curr, open, close + 1, n);  // Recurse with updated close count
            curr.pop_back();               // Backtrack: remove the ')' we added
        }
    }
    /**
     * Main function to generate all valid parentheses combinations
     * param n: Number of pairs of parentheses
     * return: Vector containing all valid combinations
     */
    vector<string> generateParenthesis(int n) {
        string curr = "";  // Start with empty string
        generate(curr, 0, 0, n);  // Begin recursion with 0 open and 0 close brackets
        return ans;  // Return all generated combinations
    }
};