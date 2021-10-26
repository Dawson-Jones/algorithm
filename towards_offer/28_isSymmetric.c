// same as leetcode 101
bool *same(struct TreeNode *a, struct TreeNode *b) {
    if (a == NULL && b == NULL)
        return true;
    if (a == NULL || b == NULL)
        return false;
    if (a->val != b->val)
        return false;
    
    return same(a->left, b->right) && same(a->right, b->left);
}

bool isSymmetric(struct TreeNode* root){
    if (!root)
        return true;

    return same(root->left, root->right);
}