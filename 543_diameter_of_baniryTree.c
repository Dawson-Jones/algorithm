#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int recursive(struct TreeNode *vertex, int *ans) {
    if (vertex == NULL)
        return 0;
    int LeftDeep  = recursive(vertex->left, ans);
    int RightDeep = recursive(vertex->right, ans);
    *ans = *ans > LeftDeep + RightDeep + 1 ? *ans : LeftDeep + RightDeep + 1;
    return (LeftDeep > RightDeep ? LeftDeep : RightDeep) + 1;
}

int diameterOfBinaryTree(struct TreeNode *root) {
    int deep = 1;
    recursive(root, &deep);
    return deep - 1;
}

int main(int argc, char const *argv[]) {
    return 0;
}
