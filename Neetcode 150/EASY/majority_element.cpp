class Solution {//Moore Voting algorithm - works only when there is a Majority element
//O(N) S(1)
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority_idx = 0;
        int count = 1;
        for(int i = 1;i<n;i++){
            if(nums[majority_idx]==nums[i]){//if repeats count ++
                count++;
            }
            else count--;//new candidate count--
            if(count == 0){//if count = 0 update the majority candidate starting from count 1
                majority_idx = i;
                count = 1;
            }
        }
        return nums[majority_idx];
    }
};