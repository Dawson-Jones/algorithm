void dfs(struct TreeNode *root, int *k, int *res) {
    if (!root) return;
    dfs(root->right, k, res);
    if (!*k) return;
    if (!--(*k)) {
        *res = root->val;
    }
    dfs(root->left, k, res);
}

int kthLargest(struct TreeNode *root, int k) {
    int res;
    dfs(root, &k, &res);
    return res;
}