/*
给定一个二叉树，找出其最小深度。

给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度 2 。
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int minDepth(struct TreeNode *root) {
    if (!root) return 0;
    if (!root->left) 
        return minDepth(root->right) + 1;
    if (!root->right) 
        return minDepth(root->left) + 1;

    int l_deep = minDepth(root->left);
    int r_deep = minDepth(root->right);
    return l_deep < r_deep ? l_deep + 1 : r_deep + 1;
}