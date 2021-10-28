class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        return helper(root, k)->val;
    }
    TreeNode *helper(TreeNode *root, int &k) {
        if (!root)
            return nullptr;

        TreeNode *tmp;
        tmp = helper(root->right, k);
        if (tmp)
            return tmp;

        if (!--k)
            return root;

        tmp = helper(root->left, k);
        if (tmp)
            return tmp;

        return nullptr;
    }
};