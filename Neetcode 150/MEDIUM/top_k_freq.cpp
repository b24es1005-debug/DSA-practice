class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; //counting freq
        for (int num : nums) freq[num]++;
        
        vector<pair<int, int>> vec; //value->freq to freq->value
        for (auto& [num, count] : freq) {
            vec.push_back({count, num});
        }
        
        sort(vec.begin(), vec.end(), greater<pair<int, int>>()); //descending order sort based on key
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(vec[i].second);
        }
        return result;
    }
};