#include "../utils/utilsLib.h"

bool helper(struct TreeNode *root, long min_num, long max_num) {
    if (!root) return true;
    if (root->val <= min_num || root->val >= max_num) return false;
    return helper(root->left, min_num, root->val) && helper(root->right, root->val, max_num);
}

bool isValidBST(struct TreeNode *root) {
    return helper(root, LONG_MIN, LONG_MAX);
}