/*
 * 根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

 */

#include "utils/utilsLib.h"

struct TreeNode *
recursive(int *cur_preOrderIndex, int *preOrder, int *PSposSet, int *NGposSet, int inOrderSt, int inOrderEd,
          int preOrderEd) {
    if (*cur_preOrderIndex > preOrderEd) return 0;
    
    struct TreeNode *vertex = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    vertex->val = preOrder[*cur_preOrderIndex];

    int cur_inorder_index;
    if (preOrder[*cur_preOrderIndex] < 0)
        cur_inorder_index = NGposSet[-preOrder[*cur_preOrderIndex]];
    else
        cur_inorder_index = PSposSet[preOrder[*cur_preOrderIndex]];

    (*cur_preOrderIndex)++;     // 用来递归的下一个 preorder 目标值
    if (cur_inorder_index <= inOrderSt) 
        vertex->left = 0;
    else
        vertex->left = recursive(cur_preOrderIndex, preOrder, PSposSet, NGposSet, inOrderSt, cur_inorder_index - 1,
                                 preOrderEd);

    if (cur_inorder_index >= inOrderEd)
        vertex->right = 0;
    else
        vertex->right = recursive(cur_preOrderIndex, preOrder, PSposSet, NGposSet, cur_inorder_index + 1, inOrderEd,
                                  preOrderEd);

    return vertex;
}

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize) {
    int PSposSet[3000];
    int NGposSet[3000];
    for (int i = 0; i < inorderSize; ++i) {
        if (inorder[i] < 0)
            NGposSet[-inorder[i]] = i;
        else
            PSposSet[inorder[i]] = i;
    }

    int cur_preorder_index = 0;
    return recursive(&cur_preorder_index, preorder, PSposSet, NGposSet, 0, inorderSize - 1, preorderSize - 1);
}

int main() {
    int preorder[] = {1, 2, 4, 5, 7, 3, 6, 8, 9};
    int inorder[] = {4, 2, 7, 5, 1, 3, 8, 6, 9};
    struct TreeNode *vertex = buildTree(preorder, sizeof(preorder) / sizeof(int), inorder,
                                        sizeof(inorder) / sizeof(int));

    int returnSize;
    int *res = preorderTraversal(vertex, &returnSize);
    printf("returnSize: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d\n", res[i]);

}