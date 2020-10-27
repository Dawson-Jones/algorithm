#include "utils/utilsLib.h"

void recur(struct TreeNode *cur, int *res, int *returnSize) {
    if (!cur) return;

    res[(*returnSize)++] = cur->val;
    recur(cur->left, res, returnSize);
    recur(cur->right, res, returnSize);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    int *res = (int *) malloc(sizeof(int) * 100);
    *returnSize = 0;
    recur(root, res, returnSize);
    return res;
}