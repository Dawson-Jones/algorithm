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


int dfs(struct TreeNode *cur_node) {
    if (!cur_node) return 0;
    int l = dfs(cur_node->left);
    int r = dfs(cur_node->right);

    if (l == -1 || r == -1 || abs(l - r) > 1)
        return -1;

    return 1 + (l > r ? l : r);
}

bool isBalanced(struct TreeNode* root) {
    return recursive(root) != -1;
}

int main() {
    struct TreeNode test = {
            1,
            NULL,
            NULL
    };
    printf("res: %d", isBalanced(&test));
}