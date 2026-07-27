class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int n : nums){
            s+=n;
        }
        if(s%2!=0) return false;//it must be even so that the other can have half of it
        vector<bool> dp(s/2 +1,false);//follows a normal subset sum equals to target.
        dp[0] = true;
        for(int x : nums){
            for(int j = s/2;j>=x;j--){
                dp[j] = dp[j] || dp[j-x];
            }
        }
        return dp[s/2];
    }
};