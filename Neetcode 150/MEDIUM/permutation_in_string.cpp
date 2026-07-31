class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();

        if (n1 > n2) return false;

        vector<int> need(26, 0), window(26, 0);

        // Frequency of s1 and first window of s2
        for (int i = 0; i < n1; i++) {
            need[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        // Check first window
        if (need == window) return true;

        // Slide the window
        for (int i = n1; i < n2; i++) {
            window[s2[i] - 'a']++;               // Add new character
            window[s2[i - n1] - 'a']--;          // Remove leftmost character

            if (need == window)
                return true;
        }

        return false;
    }
};