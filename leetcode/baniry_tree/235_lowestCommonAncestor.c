struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    while (root) {
        if (root->val > p->val && root->val > q->val){
            root = root->left;
            continue;
        }
        if (root->val < p->val && root->val < q->val){
            root = root->right;
            continue;
        }
        
        return root;
    }
    return root;
}