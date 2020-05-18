/*
不相邻子数组的最大值, 且首尾连在一起

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
*/
#include <stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


// 可以记忆化递归
int rob(struct TreeNode *root) {
    if (root==0) return 0;
    int res1 = root->val
            + (root->left == 0 ? 0 : rob(root->left->left) + rob(root->left->right))
            + (root->right == 0? 0 : rob(root->right->left) + rob(root->right->right));

    int res2 = rob(root->left) + rob(root->right);
    return res1 > res2 ? res1 : res2;
}