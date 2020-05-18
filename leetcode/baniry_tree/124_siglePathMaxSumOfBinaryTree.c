/*
给定一个非空二叉树，返回其最大路径和。
本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42
*/

// 想法, 计算每个 vertex 的和 保留最大值
// 错的, 因为最大值可以只在一边, 而顶点和一定包括了两边

// 想法 2, 后续遍历

#include <limits.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int travel(struct TreeNode *vertex, int *res) {
    if (!vertex) return 0;
    int leftMax  = max(travel(vertex->left, res), 0);  // 不选这个路径就是 0
    int rightMax = max(travel(vertex->right, res),0);  // 不选这个路径就是 0
    *res = max(*res, leftMax + rightMax + vertex->val);
    return vertex->val + max(leftMax, rightMax);  // 返回给上游单路径最大值
}

int maxPathSum(struct TreeNode *root) {
//    int res = 1<<31;     // 这个是最小值, 但是力扣不过
    int res = ~(1<<30);
    if (!root) return 0;
    travel(root, &res);
    return res;
}