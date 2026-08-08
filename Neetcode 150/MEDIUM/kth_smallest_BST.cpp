class Solution {
public:
    TreeNode* ans = NULL;
    void dfs(TreeNode* root, int& k){
        if(root==NULL || ans!=NULL){
            return;
        }
        dfs(root->left,k);//checking left
        
        if(ans!=NULL){
            return;
        }
        k--;//marking the node as visited so k--
        if(k==0){//checking whether we have found
            ans = root;
            return;
        }
        dfs(root->right,k);//else check the right subtree
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return ans->val;
    }
};
