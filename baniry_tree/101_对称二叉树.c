/*
 * 给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#include <stdbool.h>
#include <memory.h>
#include <stdio.h>

bool isSymmetric(struct TreeNode *root) {
    struct TreeNode *stack[100][2];
    if (!root) return true;
    stack[0][0] = root->left;
    stack[0][1] = root->right;
    int stackCount = 1;
    while (stackCount--) {
        if (!stack[stackCount][0] || !stack[stackCount][1]){
            if (!stack[stackCount][0] && !stack[stackCount][1]) continue;
            else return false;
        }

        if ((stack[stackCount][0]->val) != (stack[stackCount][1]->val)) return false;
        struct TreeNode *cur1 = stack[stackCount][0];
        struct TreeNode *cur2 = stack[stackCount][1];
        stack[stackCount][0] = cur1->left;
        stack[stackCount][1] = cur2->right;
        stack[stackCount + 1][0] = cur1->right;
        stack[stackCount + 1][1] = cur2->left;
        stackCount+=2;
    }
    return true;
}

int main() {
    struct TreeNode test4 = {1, 0, 0};
    struct TreeNode test5 = {3, 0, 0};
    struct TreeNode test6 = {0, 0, 0};
    struct TreeNode test7 = {3, 0, 0};
    struct TreeNode test2 = {2, &test4, &test5};
    struct TreeNode test3 = {2, &test6, &test7};
    struct TreeNode test1 = {1, &test2, &test3};
    int res = isSymmetric(&test1);
    printf("res: %d", res);
}