class Solution {
public:
    bool dfs(TreeNode* root, long long minv, long long maxv){
        if(root == NULL) return true;
        if(root->val <= minv || root->val >=maxv) return false;
        return dfs(root->left,minv,root->val) && dfs(root->right,root->val,maxv);//
        //entire left subtree must be lower than root as well as the entire right subtree must be gigher than root
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,INT_MIN,INT_MAX);
    }
};
