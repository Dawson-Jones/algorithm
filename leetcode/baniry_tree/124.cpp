class Solution {
public:
    int res = INT32_MIN;

    int helper(TreeNode *root) {
        if (!root)
            return 0;

        int left = helper(root->left);
        int right = helper(root->right);
        res = max({left + root->val, right + root->val, left + right + root->val, root->val, res});
        return max({left + root->val, right + root->val, root->val});
    }

    int maxPathSum(TreeNode *root) {
        int x = helper(root);
        return res > x ? res : x;
    }
};