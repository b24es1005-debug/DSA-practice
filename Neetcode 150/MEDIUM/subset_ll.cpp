class Solution {
public:
    vector<vector<int>> ans;  // Stores all unique subsets
    vector<int> curr;         // Current subset being built
    // Backtracking function to generate all unique subsets
    void backtrack(int start, vector<int>& nums) {
        // Add the current subset to the answer
        ans.push_back(curr);
        // Try adding each element from 'start' to the end
        for (int i = start; i < nums.size(); i++) {//here not pick is not explicit as the for loop will take care of it.
            // Skip duplicates: if current element is same as previous
            if (i > start && nums[i] == nums[i - 1])
                continue;
            // Include nums[i] in current subset
            curr.push_back(nums[i]);
            // Recurse with next starting index
            backtrack(i + 1, nums);
            // Backtrack: remove the element
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Sort to handle duplicates and make skipping easier
        sort(nums.begin(), nums.end());
        // Start backtracking from index 0
        backtrack(0, nums);
        return ans;
    }
};

/*
Time Complexity: O(N * 2^N) 
- In worst case (all unique elements), we generate 2^N subsets.
- Copying each subset (of average length N/2) to answer takes O(N) time per subset.
- Overall: O(N * 2^N)

Space Complexity: O(N * 2^N) 
- To store all subsets in the answer.
- Excluding the output space, the recursion stack uses O(N) space.
*/ 