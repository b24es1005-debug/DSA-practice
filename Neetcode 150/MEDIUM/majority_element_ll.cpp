class Solution {//atmost 2 numbers can repeat more than n/3 times.
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        // Extended Moore Voting - tracks 2 candidates
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == candidate1) {
                count1++;
            }
            else if (nums[i] == candidate2) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        // Reset counts for verification
        count1 = 0;
        count2 = 0;
        
        // Count actual occurrences
        for (int i = 0; i < n; i++) {
            if (nums[i] == candidate1) count1++;
            else if (nums[i] == candidate2) count2++;
        }
        
        vector<int> result;
        if (count1 > n / 3) result.push_back(candidate1);
        if (count2 > n / 3) result.push_back(candidate2);
        
        return result;
    }
};