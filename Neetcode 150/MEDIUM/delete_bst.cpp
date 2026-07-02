TreeNode* findMin(TreeNode* root){

    while(root->left)
        root=root->left;

    return root;
}

TreeNode* deleteNode(TreeNode* root,int key){

    if(root==nullptr)
        return nullptr;

    if(key<root->val)
        root->left=deleteNode(root->left,key);

    else if(key>root->val)
        root->right=deleteNode(root->right,key);

    else{

        if(root->left==nullptr)
            return root->right;

        if(root->right==nullptr)
            return root->left;

        TreeNode* temp=findMin(root->right);

        root->val=temp->val;

        root->right=deleteNode(root->right,temp->val);
    }

    return root;
}