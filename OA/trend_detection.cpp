/*
Question: For each customer in C_ID, find the trend based on the increasing order of timestamp. 
If trend shows deviation i.e. not constantly increasing or constantly decreasing, return false else return true.

Time Complexity: O(N log N) where N is the number of data points (due to sorting per customer)
Space Complexity: O(N) for storing grouped customer data
*/

class Solution {
public:
    unordered_map<string, bool> checkTrendConsistency(
        const vector<string>& C_ID,
        const vector<int>& TimeStamp,
        const vector<int>& Trend
    ) {
        unordered_map<string, vector<pair<int, int>>> customerData;
        
        for (size_t i = 0; i < C_ID.size(); i++) {
            customerData[C_ID[i]].push_back({TimeStamp[i], Trend[i]});
        }
        
        unordered_map<string, bool> result;
        
        for (auto& entry : customerData) {
            string customerId = entry.first;
            vector<pair<int, int>>& dataPoints = entry.second;
            
            sort(dataPoints.begin(), dataPoints.end(), 
                 [](const pair<int, int>& a, const pair<int, int>& b) {
                     return a.first < b.first;
                 });
            
            vector<int> trends;
            for (const auto& point : dataPoints) {
                trends.push_back(point.second);
            }
            
            bool isIncreasing = true;
            bool isDecreasing = true;
            
            for (size_t i = 0; i < trends.size() - 1; i++) {
                if (trends[i] >= trends[i + 1]) {
                    isIncreasing = false;
                }
                if (trends[i] <= trends[i + 1]) {
                    isDecreasing = false;
                }
            }
            
            result[customerId] = isIncreasing || isDecreasing;
        }
        
        return result;
    }
};