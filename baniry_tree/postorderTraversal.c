#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    void recurTree(struct TreeNode*, int*, int*);
    int length = 0;
    int *arr = (int*)calloc(4, 100);
    if(arr==NULL) exit(1);
    if(root==NULL){
        *returnSize = 0;
        return arr;
    }
    recurTree(root, arr, &length);
    *returnSize = length;
    return arr;
}
void recurTree(struct TreeNode* root, int* arr, int *length){
    if(root->left!=NULL)
        recurTree(root->left, arr, length);
    if(root->right!=NULL)
        recurTree(root->right, arr, length);
    arr[*length] = root->val;
    (*length)++; 
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