#include "../utils/utilsLib.h"

struct TreeNode *lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q){
    if (!root || root == p || root == q) return root;

    // 后序遍历
    struct TreeNode *left   = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *right  = lowestCommonAncestor(root->right, p, q);

    // 在往上冒泡的过程中, 始终把结果锁定
    if (!left)  return right;
    if (!right) return left;

    // only left && right both are not null
    return root;
}