bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (!(p || q))
        return true;
    if (!p || !q)
        return false;
    if (p->val == q->val)
        return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);

    return false;
}

bool isSymmetric(struct TreeNode* root){
    return isSameTree(root, root);
}