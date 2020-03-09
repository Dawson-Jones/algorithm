#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include<stdbool.h>
// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int recursive(struct TreeNode* vertex, int *ans){
    if(vertex==NULL)
        return 0;
    int L = recursive(vertex->left, ans);
    int R = recursive(vertex->right, ans);
    *ans = *ans>L+R+1?*ans:L+R+1;
    return (L>R?L:R)+1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    int deep = 1;
    recursive(root, &deep);
    return deep-1;
}

int main(int argc, char const *argv[]){
    return 0;
}
