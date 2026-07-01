
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(l != NULL && r != NULL) return root;//if both left and right != NULL then defo there is a root LCA
        return l != NULL ? l:r;//if l!=NULL then l is LCA or else r is the LCA
    }
};