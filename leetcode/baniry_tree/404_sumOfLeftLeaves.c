int helper(struct TreeNode *root, bool is_left) {
    if (!root)
        return 0;
    if (!(root->left || root->right)) {
        if (is_left)
            return root->val;
        else
            return 0;
    }

    return helper(root->left, true) + helper(root->right, false);
}

int sumOfLeftLeaves(struct TreeNode* root){
    return helper(root, false);
}
