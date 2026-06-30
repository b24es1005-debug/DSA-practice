class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());//sorting to reduce the time compexity
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i<n-2;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;//check if its unique
            int j = i+1;
            int k = n-1;
            while(j<k){
            
                if(nums[i] + nums[j] + nums[k] == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;//iterating through the duplicates of j and k bcs we only need unique op
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
                else if(nums[i] + nums[j] + nums[k] < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
        
        }
        return ans;
    }
};
/*Complexity
Time: O(n²)
Sorting: O(n log n)
Two pointers for each i: O(n²) overall
Space: O(1) (excluding the output)*/