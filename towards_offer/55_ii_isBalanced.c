int max_depth(struct TreeNode *root) {
    if (!root)
        return 0;

    int l = max_depth(root->left);
    int r = max_depth(root->right);
    if (l == -1 || r == -1 || abs(l - r) > 1)
        return -1;

    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root){
   return max_depth(root) >= 0;
}