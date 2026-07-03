class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        findsubset(0,nums,sub,ans);
        return ans;
    }
    void findsubset(int index, vector<int>& nums,vector<int>& sub,vector<vector<int>>& ans){
        if(index == nums.size()){
            ans.push_back(sub);
            return;
        }
        //for each index: decide to either pick or not pick

        //picking
        sub.push_back(nums[index]);//pick nums[index] then move to next
        findsubset(index+1,nums,sub,ans);//index + 1 bcs I have picked the index already
        sub.pop_back();//after finding one sol pop that

        //not picking
        findsubset(index+1,nums,sub,ans);
    }

};