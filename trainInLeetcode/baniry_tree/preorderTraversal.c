#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    void recurTree(struct TreeNode *, int *, int *);
    int length = 0;
    int *arr = (int *) calloc(4, 100);
    if (arr == NULL) exit(1);
    if (root == NULL) {
        *returnSize = 0;
        return arr;
    }
    recurTree(root, arr, &length);
    *returnSize = length;
    return arr;
}

void recurTree(struct TreeNode *root, int *arr, int *length) {
    arr[*length] = root->val;

    /* *arr = root->val;
       arr++;
     * 这样的操作不可以

     * 因为, arr本身是一个指针'变量', 而不是指针变量的指针,
     * 而在递归的过程中, 传递的是arr这个变量,
     * 所以在遍历left的时候left中修改的arr, 并不会修改到right上
    */

    (*length)++;  // 这个地方不能用 *length++
    if (root->left)
        recurTree(root->left, arr, length);
    if (root->right)
        recurTree(root->right, arr, length);
}

int main(int argc, char const *argv[]) {
    struct TreeNode vartex1 = {1, NULL, NULL};
    struct TreeNode vartex2 = {2, NULL, NULL};
    struct TreeNode vartex3 = {3, &vartex1, &vartex2};
    int returnSize;
    // int *res = preorderTraversal(&vartex3, &returnSize);
    int *res = preorderTraversal(NULL, &returnSize);
    printf("returnSize: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d\n", res[i]);
    free(res);
    return 0;
}