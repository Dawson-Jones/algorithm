class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> stk;
        TreeNode *cur;

        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
                continue;
            }

            root = stk.top(); stk.pop();
            if (--k == 0)
                return root->val;
            root = root->right;
        }

        return -1;
    }
};
