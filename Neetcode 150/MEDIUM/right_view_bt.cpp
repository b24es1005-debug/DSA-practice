
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rec(root,0,ans);
        return ans;
    }
    void rec(TreeNode* root, int level,vector<int>& ans){
        if(root == NULL) return;
        if(level == ans.size()){//if you encounter a node for first time push it.
            ans.push_back(root->val);
        }
        rec(root->right,level+1,ans);//right comes first bcs right view. when right node encountered for first time push it.
        rec(root->left,level+1,ans);
    }
};