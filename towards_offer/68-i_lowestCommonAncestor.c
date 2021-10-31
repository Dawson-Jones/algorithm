struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root)
        return NULL;
    if (root == p || root == q)
        return root;
    struct TreeNode *l = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *r = lowestCommonAncestor(root->right, p, q);
    if (l && r)
        return root;
    if (l)
        return l;
    if (r)
        return r;
    return NULL;
}