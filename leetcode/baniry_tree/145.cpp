class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *prev = nullptr;

        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            if (root->right && root->right != prev) {
                root = root->right;
                continue;
            }

            stk.pop();
            res.push_back(root->val);
            prev = root;
            root = nullptr;
        }
        return res;
    }
};
