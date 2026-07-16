class Solution {
public://num will be the start if (num - 1) did not exist. So check for num-1 and start the seq.
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());//using this bcs search is O(1).
        int longest = 0;
        for (int num : st) {
            // Start only from the beginning of a sequence
            if (st.find(num - 1) == st.end()) {//num-1 did not exist then add that to seq
                int curr = num;
                int len = 1;

                while (st.find(curr + 1) != st.end()) {//check the upcoming num with diff = 1
                    curr++;
                    len++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};