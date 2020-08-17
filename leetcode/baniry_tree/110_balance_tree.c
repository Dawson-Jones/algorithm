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


int recursive(struct TreeNode *cur_node) {
    if (!cur_node) return 1;
    int left_level = recursive(cur_node->left);
    int right_level = recursive(cur_node->right);

    if (left_level == -1 || right_level == -1 || abs(left_level - right_level) > 1)
        return -1;

    return left_level > right_level ? left_level + 1 : right_level + 1;
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