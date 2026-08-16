class Solution {//LC 56
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.empty())
            return {};
        // Sort by starting point
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        // First interval
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            // Overlap
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] =
                    max(ans.back()[1], intervals[i][1]);
            }
            // No overlap
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};