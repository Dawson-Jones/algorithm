/*
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点的左右两个子树的高度差的绝对值不超过1。

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。
 */
#include "utils/utilsLib.h"


int max_depth(struct TreeNode *root) {
    if (!root)
        return 0;

    int l = max_depth(root->left);
    int r = max_depth(root->right);
    if (l == -1 || r == -1 || abs(l - r) > 1)
        return -1;

    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root){
   return max_depth(root) >= 0;
}

int main() {
    struct TreeNode test = {
            1,
            NULL,
            NULL
    };
    printf("res: %d", isBalanced(&test));
}