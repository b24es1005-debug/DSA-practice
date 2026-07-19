class Solution {//return the non repeating number in vector of twice repeating numbers
public:
    int singleNumber(vector<int>& nums) {
        int a = nums[0];
        for(int i = 1;i<nums.size();i++){//same numbers become 0 after xor
            a = a^nums[i];//xor of same number results in 0; 
            //even if one number is not repeating it value is retained
        }
        return a;
    }
};