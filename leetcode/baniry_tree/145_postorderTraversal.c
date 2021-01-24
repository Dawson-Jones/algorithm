#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void recurTree(struct TreeNode *root, int *arr, int *length) {
    if (!root) return;

    recurTree(root->left, arr, length);
    recurTree(root->right, arr, length);

    arr[(*length)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int *arr = (int *) malloc(sizeof(int) * 100);
    if (!arr) exit(1);

    *returnSize = 0;
    recurTree(root, arr, returnSize);
    return arr;
}


int main(int argc, char const *argv[])
{
    struct TreeNode vartex1 = {1, NULL, NULL};
    struct TreeNode vartex2 = {2, NULL, NULL};
    struct TreeNode vartex3 = {3, &vartex1, &vartex2};
    int returnSize;
    int *res = postorderTraversal(&vartex3, &returnSize);
    printf("returnSize: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d\n", res[i]);
    free(res);
    return 0;
}