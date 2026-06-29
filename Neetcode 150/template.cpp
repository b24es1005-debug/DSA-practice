#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //function here

};

int main() {
    Solution sol;

    // Input

    // Call function

    // Print answer

    return 0;
}

/* Below is the template to return a LL, when we need to create a LL we must create every node
ListNode* dummy = new ListNode(0);
ListNode* tail = dummy; */

// Below is a two sum example

/* #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = sol.twoSum(nums, target);

    if (!ans.empty()) {
        cout << "Indices: ";
        for (int x : ans)
            cout << x << " ";
        cout << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}*/