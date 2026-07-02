
class Solution {
public:
    int dfs(TreeNode* root,int& ans){
        if(root == NULL) return 0;
        int l = max(0,dfs(root->left,ans));//only taking if positive else avoid
        int r = max(0,dfs(root->right,ans));
        ans = max(ans,l+root->val+r);//checking the full path from l to root to r
        return root->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root,ans);
        return ans;
    }
};