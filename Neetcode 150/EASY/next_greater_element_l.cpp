class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        // Find next greater element for every element in nums2
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Build answer for nums1
        vector<int> ans;

        for (int num : nums1) {
            if (nextGreater.count(num)) {
                ans.push_back(nextGreater[num]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};