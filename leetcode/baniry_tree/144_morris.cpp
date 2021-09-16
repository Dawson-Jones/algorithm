public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root)
            return res;
        TreeNode *most_right;
        while (root) {
            if (root->left) {
                most_right = find_most_right(root, root->left);
                if (most_right->right == nullptr) {
                    // cout << root->val << "---" << endl;
                    res.push_back(root->val);
                    most_right->right = root;
                    root = root->left;
                } else if (most_right->right == root) {
                    // cout << root->val << "+++" << endl;
                    most_right->right = nullptr;
                    root = root->right;
                }
            } else {
                // cout << root->val << "===" << endl;
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
