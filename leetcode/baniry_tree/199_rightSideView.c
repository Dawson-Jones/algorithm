/*
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
*/

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void travel(struct TreeNode *vertex, int level, int *res, int *returnSize){
    if (!vertex) return;
    if (level > *returnSize)
        res[(*returnSize)++] = vertex->val;

    travel(vertex->right, level+1, res, returnSize);
    travel(vertex->left, level+1, res, returnSize);
}

int *rightSideView(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;
    int *res = (int *) malloc(1000 * sizeof(int));
    if (!res) 
        exit(1);

    travel(root, 1, res, returnSize);
    return res;
}

