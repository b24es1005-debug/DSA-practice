bool hasPathSum(TreeNode* root,int target){

    if(root==nullptr)
        return false;

    if(root->left==nullptr &&
       root->right==nullptr)

        return target==root->val;

    return hasPathSum(root->left,target-root->val)
        || hasPathSum(root->right,target-root->val);
}
int ans=INT_MIN;

int dfs(TreeNode* root){

    if(root==nullptr)
        return 0;

    int left=max(0,dfs(root->left));
    int right=max(0,dfs(root->right));

    ans=max(ans,left+right+root->val);

    return root->val+max(left,right);
}