class Solution {
public:

    int dfs(TreeNode* root, int maxSoFar){

        if(root==nullptr)//base case
            return 0;

        int good=0;

        if(root->val>=maxSoFar)
            good=1;//this 1 gets added up for the crt conditions solved during the recursion 

        maxSoFar=max(maxSoFar,root->val);//update the child

        return good
             + dfs(root->left,maxSoFar)
             + dfs(root->right,maxSoFar);
    }

    int goodNodes(TreeNode* root) {

        return dfs(root,root->val);

    }
};
/* TC: O(n) , SC : O(h)
dfs(node, state){

    if(node==nullptr)
        return ...;

    // Use current state

    // Update state

    // Pass updated state to children

    return ...
}
Examples of this pattern include:
Count Good Nodes in Binary Tree → carry maxSoFar
Path Sum → carry currentSum
Binary Tree Maximum Path (variants) → carry path information
Pseudo-Palindromic Paths → carry digit frequencies/bitmask */