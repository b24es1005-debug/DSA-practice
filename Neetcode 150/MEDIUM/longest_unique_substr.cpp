class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {

            if (mp.count(s[r]) && mp[s[r]] >= l) {//checks if s[r] exists within the window
                l = mp[s[r]] + 1;
            }

            mp[s[r]] = r;//updating the last occured index

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
//IO: abcabcd
//OP: 4