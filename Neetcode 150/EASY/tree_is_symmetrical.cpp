class Solution {
private:
    bool isMirror(TreeNode* left,TreeNode* right){
        if(left == NULL && right == NULL) return true;//both are NULL
        if(left == NULL || right == NULL) return false;//if only one of them is NULL
        if(left->val != right->val) return false;//val check
        return isMirror(left->left,right->right) && isMirror(left->right,right->left);//comparing one side with the mirror of the other side
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isMirror(root->left,root->right);
        
    }
};