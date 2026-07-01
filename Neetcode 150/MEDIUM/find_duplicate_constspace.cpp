class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Find intersection point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find cycle entrance
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
?
/*Intuition to Remember

Don't think of the array as an array.

Think of it as a linked list:

index → value → next index

For the example [1,3,4,2,2]:

0 → 1 → 3 → 2 → 4
          ↑       |
          └───────┘

The duplicate value (2) is the entry point of the cycle. 
Once you see the array as a graph of pointers rather than a list of numbers,
Floyd's cycle detection becomes the natural solution. 
This perspective is the key insight interviewers are looking for.*/