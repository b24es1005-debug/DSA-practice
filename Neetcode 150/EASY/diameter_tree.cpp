//LC 1245: Diameter: longest path in a binary tree not necessarily from the root
class Solution {
public:
    int diameter = 0;
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        diameter = max(diameter,left+right);//max left height + max right height
        return 1+max(left,right);//when going up take this 1(this node) along with the longest child height(either left or right)
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
};
