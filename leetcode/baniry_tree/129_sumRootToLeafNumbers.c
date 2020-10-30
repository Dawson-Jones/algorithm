/*
给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
计算从根到叶子节点生成的所有数字之和。
说明: 叶子节点是指没有子节点的节点。

输入: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
输出: 1026

从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->9->1 代表数字 491.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026.
 */

#include "utils/utilsLib.h"

int sum(struct TreeNode* root, int tmp_sum)
{
    if (root == NULL) return 0;
    if (!(root->left || root->right)) {
        return tmp_sum * 10 + root->val;
    }
    return sum(root->left,  tmp_sum * 10 + root->val) +
           sum(root->right, tmp_sum * 10 + root->val);
}
int sumNumbers(struct TreeNode* root){
    return sum(root, 0);
}

int main() {
    struct TreeNode vertex3 = {3, NULL, NULL};
    struct TreeNode vertex2 = {2, NULL, NULL};
    struct TreeNode vertex1 = {1, &vertex2, &vertex3};

    printf("res: %d", sumNumbers(&vertex1));
}