class Solution {
public:
    void findcombination(int index, int target, vector<int>& arr, 
                         vector<int>& ds, vector<vector<int>>& ans) {
        // Found a valid combination
        if(target == 0) {
            ans.push_back(ds);
            return;
        }
        
        // Try all elements from current index
        for(int i = index; i < arr.size(); i++) {
            // Skip duplicates at this level
            if(i > index && arr[i] == arr[i-1]) continue;
            
            // Since array is sorted, if arr[i] > target, break
            if(arr[i] > target) break;
            
            // Pick arr[i]
            ds.push_back(arr[i]);
            findcombination(i + 1, target - arr[i], arr, ds, ans);
            //          ↑ i+1 (not index+1)
            ds.pop_back();  // Backtrack
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // ⭐ CRITICAL!
        vector<vector<int>> ans;
        vector<int> ds;
        findcombination(0, target, nums, ds, ans);
        return ans;
    }
};
/*Note:index+1 = always start from the next index (incorrect)
i+1 = start from the element after the one we picked (correct)

DRY RUN:
Sorted: [1,1,2,5,6,7,10]

findcombination(0, target=8):
├─ i=0 (value=1):
│   pick 1
│   findcombination(1, target=7):
│   ├─ i=1 (value=1):
│   │   pick 1
│   │   findcombination(2, target=6):
│   │   ├─ i=2 (value=2):
│   │   │   pick 2
│   │   │   findcombination(3, target=4):
│   │   │   ├─ i=3 (value=5):
│   │   │   │   arr[i] > target? 5 > 4 → break
│   │   │   ├─ i=4 (value=6): break
│   │   │   ├─ i=5 (value=7): break
│   │   │   ├─ i=6 (value=10): break
│   │   │   └─ Backtrack
│   │   ├─ i=3 (value=5):
│   │   │   arr[i] > target? 5 > 6? No
│   │   │   pick 5
│   │   │   findcombination(4, target=1):
│   │   │   └─ i=4 (value=6): 6 > 1 → break
│   │   ├─ i=4 (value=6):
│   │   │   arr[i] > target? 6 > 6? No (equal)
│   │   │   pick 6
│   │   │   findcombination(5, target=0):
│   │   │   └─ target==0 → ans.push([1,1,6]) ✓
│   │   ├─ i=5 (value=7):
│   │   │   arr[i] > target? 7 > 6 → break
│   │   └─ i=6 (value=10): break
│   ├─ i=2 (value=2):
│   │   // This gives [1,2,5] which equals 8
│   │   pick 2
│   │   findcombination(3, target=5):
│   │   ├─ i=3 (value=5):
│   │   │   pick 5
│   │   │   findcombination(4, target=0):
│   │   │   └─ ans.push([1,2,5]) ✓
│   │   ├─ i=4 (value=6): 6 > 5 → break
│   │   └─ i=5 (value=7): break
│   ├─ i=3 (value=5):
│   │   pick 5
│   │   findcombination(4, target=2):
│   │   ├─ i=4 (value=6): 6 > 2 → break
│   │   └─ i=5 (value=7): break
│   ├─ i=4 (value=6):
│   │   pick 6
│   │   findcombination(5, target=1):
│   │   └─ i=5 (value=7): 7 > 1 → break
│   ├─ i=5 (value=7):
│   │   pick 7
│   │   findcombination(6, target=0):
│   │   └─ ans.push([1,7]) ✓
│   └─ i=6 (value=10): 10 > 8 → break
├─ i=1 (value=1):
│   // i > index (1 > 0) and arr[1]==arr[0] → skip duplicate ✓
├─ i=2 (value=2):
│   pick 2
│   findcombination(3, target=6):
│   ├─ i=3 (value=5):
│   │   pick 5
│   │   findcombination(4, target=1):
│   │   └─ i=4 (value=6): 6 > 1 → break
│   ├─ i=4 (value=6):
│   │   pick 6
│   │   findcombination(5, target=0):
│   │   └─ ans.push([2,6]) ✓
│   └─ i=5 (value=7):
│       arr[i] > target? 7 > 6 → break
├─ i=3 (value=5):
│   pick 5
│   findcombination(4, target=3):
│   └─ i=4 (value=6): 6 > 3 → break
├─ i=4 (value=6):
│   pick 6
│   findcombination(5, target=2):
│   └─ i=5 (value=7): 7 > 2 → break
├─ i=5 (value=7):
│   pick 7
│   findcombination(6, target=1):
│   └─ i=6 (value=10): 10 > 1 → break
└─ i=6 (value=10):
    arr[i] > target? 10 > 8 → break

ans = [[1,1,6], [1,2,5], [1,7], [2,6]] ✓*/