class Solution{
public:
    int minimumRotatedSortedArray(vector<int>& nums){
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            int m = l + (r-l)/2;
            if(nums[m] > nums[r]) l = m+1;//min is in right side excluding m
            else r = m;//min is in left side including m
        }
        return nums[l];
    }
};