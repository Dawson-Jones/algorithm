// 前一种更好
int max_depth(struct TreeNode *root, int depth) {
    if (!root)
        return depth;

    int l = max_depth(root->left, depth + 1);
    int r = max_depth(root->right, depth + 1);
    if (l == -1 || r == -1 || abs(l - r) > 1)
        return -1;

    return l > r ? l : r;
}

bool isBalanced(struct TreeNode* root){
    if (!root)
        return true;
    int l = max_depth(root->left, 1);
    int r = max_depth(root->right, 1);
    return l != -1 && r != -1 && abs(l - r) <= 1;
}