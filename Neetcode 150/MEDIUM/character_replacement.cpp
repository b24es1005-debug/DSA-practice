class Solution {//LC424
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);   // frequency of characters in current window
        int left = 0;              // left pointer of sliding window
        int maxFreq = 0;           // max frequency of any single character in window
        int result = 0;            // maximum valid window length found
        for (int right = 0; right < s.size(); right++) {
            // Add new character to window
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            // Current window length
            int windowLen = right - left + 1;
            // If we need more than k replacements, shrink window from left
            while (windowLen - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
                windowLen--;          // update window length after shrinking
                // Recalculate maxFreq for the new window (optional but correct)
                maxFreq = *max_element(freq.begin(), freq.end());
            }
            // Update answer with current valid window length
            result = max(result, windowLen);
        }
        return result;
    }
};
/*You are given a string s and an integer k. 
You can choose any character of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.*/