struct TreeNode* invertTree(struct TreeNode* root){
    if (!root)
        return NULL;
    
    struct TreeNode *tmp = root->right;
    root->right = invertTree(root->left);
    root->left = invertTree(tmp);
    
    return root;
}