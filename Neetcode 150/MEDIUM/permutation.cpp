class Solution {
public:
    void perm(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, vector<int>& freq) {
        // Base case: if ds size equals nums size, we have a complete permutation
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        
        // Try all elements
        for(int i = 0; i < nums.size(); i++) {
            // If element is not used yet
            if(!freq[i]) {
                // Pick the element
                ds.push_back(nums[i]);
                freq[i] = 1;  // Mark as used
                
                // Recurse
                perm(nums, ds, ans, freq);
                
                // Backtrack
                freq[i] = 0;  // Mark as unused
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);  // ✅ Track used elements
        
        // Start recursion with a single call
        perm(nums, ds, ans, freq);
        
        return ans;
    }
};
/*
DRY RUN:
permute([1,2,3]):
  ans = []
  ds = []
  freq = [0,0,0]
  
  perm([1,2,3], [], [], [0,0,0]):

├─ i=0 (nums[0]=1):
│   freq[0]=0 → available
│   ds=[1], freq=[1,0,0]
│   perm([1,2,3], [1], [], [1,0,0]):
│   ├─ i=0: freq[0]=1 → skip
│   ├─ i=1 (nums[1]=2):
│   │   freq[1]=0 → available
│   │   ds=[1,2], freq=[1,1,0]
│   │   perm([1,2,3], [1,2], [], [1,1,0]):
│   │   ├─ i=0: freq[0]=1 → skip
│   │   ├─ i=1: freq[1]=1 → skip
│   │   ├─ i=2 (nums[2]=3):
│   │   │   freq[2]=0 → available
│   │   │   ds=[1,2,3], freq=[1,1,1]
│   │   │   perm([1,2,3], [1,2,3], [], [1,1,1]):
│   │   │   └─ ds.size() == nums.size() → ans.push_back([1,2,3]) ✓
│   │   │   └─ Backtrack: freq[2]=0, ds=[1,2]
│   │   └─ Backtrack: freq[1]=0, ds=[1]
│   ├─ i=2 (nums[2]=3):
│   │   freq[2]=0 → available
│   │   ds=[1,3], freq=[1,0,1]
│   │   perm([1,2,3], [1,3], [], [1,0,1]):
│   │   ├─ i=0: freq[0]=1 → skip
│   │   ├─ i=1 (nums[1]=2):
│   │   │   freq[1]=0 → available
│   │   │   ds=[1,3,2], freq=[1,1,1]
│   │   │   perm([1,2,3], [1,3,2], [], [1,1,1]):
│   │   │   └─ ans.push_back([1,3,2]) ✓
│   │   └─ Backtrack: freq[2]=0, ds=[1]
│   └─ Backtrack: freq[0]=0, ds=[]
│
├─ i=1 (nums[1]=2):
│   freq[1]=0 → available
│   ds=[2], freq=[0,1,0]
│   perm([1,2,3], [2], [], [0,1,0]):
│   ├─ i=0 (nums[0]=1):
│   │   freq[0]=0 → available
│   │   ds=[2,1], freq=[1,1,0]
│   │   perm([1,2,3], [2,1], [], [1,1,0]):
│   │   ├─ i=2 (nums[2]=3):
│   │   │   ds=[2,1,3], freq=[1,1,1]
│   │   │   perm(...) → ans.push_back([2,1,3]) ✓
│   │   └─ Backtrack
│   ├─ i=2 (nums[2]=3):
│   │   freq[2]=0 → available
│   │   ds=[2,3], freq=[0,1,1]
│   │   perm([1,2,3], [2,3], [], [0,1,1]):
│   │   ├─ i=0 (nums[0]=1):
│   │   │   freq[0]=0 → available
│   │   │   ds=[2,3,1], freq=[1,1,1]
│   │   │   perm(...) → ans.push_back([2,3,1]) ✓
│   │   └─ Backtrack
│   └─ Backtrack: freq[1]=0, ds=[]
│
└─ i=2 (nums[2]=3):
    freq[2]=0 → available
    ds=[3], freq=[0,0,1]
    perm([1,2,3], [3], [], [0,0,1]):
    ├─ i=0 (nums[0]=1):
    │   ds=[3,1], freq=[1,0,1]
    │   perm([1,2,3], [3,1], [], [1,0,1]):
    │   ├─ i=1 (nums[1]=2):
    │   │   ds=[3,1,2], freq=[1,1,1]
    │   │   perm(...) → ans.push_back([3,1,2]) ✓
    │   └─ Backtrack
    ├─ i=1 (nums[1]=2):
    │   ds=[3,2], freq=[0,1,1]
    │   perm([1,2,3], [3,2], [], [0,1,1]):
    │   ├─ i=0 (nums[0]=1):
    │   │   ds=[3,2,1], freq=[1,1,1]
    │   │   perm(...) → ans.push_back([3,2,1]) ✓
    │   └─ Backtrack
    └─ Backtrack: freq[2]=0, ds=[]

ans = [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]] ✓*/