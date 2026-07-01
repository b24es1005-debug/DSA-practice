class Solution {
public:
    bool isEqual(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        return (p->val == q->val) && isEqual(p->left,q->left) && isEqual(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root == NULL) return false;
        if(isEqual(root,subroot)) return true;
        return isSubtree(root->left,subroot) || isSubtree(root->right,subroot);
        

    }
};
