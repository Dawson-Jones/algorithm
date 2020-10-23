/*
给定一个二叉树，找出其最大深度。

给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int maxDepth(struct TreeNode *root) {
    if (!root) return 0;
    int l_deep = maxDepth(root->left);
    int r_deep = maxDepth(root->right);
    return l_deep > r_deep ? l_deep + 1 : r_deep + 1;
}

int main(){
    // 这个题没思考直接写出来了, 🐮🍺!!!
}
