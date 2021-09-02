void flatten(struct TreeNode* root){
    if (!root) return;
    
    struct TreeNode *cur = root;
    struct TreeNode *restore_right;
    struct TreeNode *next;
    while (cur) {
        restore_right = cur->right;
        cur->right = cur->left;
        cur->left = NULL;
        next = cur->right ? cur->right : restore_right;
        while (cur->right) {
            cur = cur->right;
        }
        cur->right = restore_right;
        cur = next;
    }
}