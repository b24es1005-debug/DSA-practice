class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums,int target){
        vector<vector<int>> ans;
        vector<int> store;
        findcombination(0,nums,target,store,ans);
        return ans;
    }
    void findcombination(int index,vector<int>& arr, int target,vector<int> ds, vector<vector<int>>& ans){
        //base case
        if(index == arr.size()){
            if(target == 0){
                ans.push_back(ds);//npt const time, bcs pushing the entire ds
            }
            return;//come upside and check for other combinations
        }
        if(arr[index] <= target){//consider picking
            ds.push_back(arr[index]);
            findcombination(index,arr,target-arr[index],ds,ans);
            ds.pop_back();//if you have found or not found just pop after checking 
        }
        findcombination(index+1,arr,target,ds,ans);//move next index bcs not picking
    }
};