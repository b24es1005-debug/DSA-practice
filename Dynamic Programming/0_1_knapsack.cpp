class Solution {//TC: n*W   SC: n*W
public:

int solve(int i,
          int W,
          vector<int>& wt,
          vector<int>& val,
          vector<vector<int>>& dp){

    if(i==wt.size())//reached the end return 0
        return 0;

    if(dp[i][W]!=-1)//already found return 
        return dp[i][W];

    int notTake=solve(i+1,W,wt,val,dp);//just move to next idx without the current val

    int take=0;

    if(wt[i]<=W)
        take=val[i]+solve(i+1,//take the curr val and move to next idx
                          W-wt[i],
                          wt,
                          val,
                          dp);

    return dp[i][W]=max(take,notTake);
}

int knapsack(vector<int>& wt,
             vector<int>& val,
             int W){

    int n=wt.size();

    vector<vector<int>> dp(
        n,
        vector<int>(W+1,-1));

    return solve(0,W,wt,val,dp);
}

};



/* Most optimised DP TC: n*W SC: n
vector<int> dp(W + 1, 0);

for (int i = 0; i < n; i++) {
    for (int cap = W; cap >= wt[i]; cap--) {
        dp[cap] = max(dp[cap], val[i] + dp[cap - wt[i]]);
    }
}

return dp[W];
*/