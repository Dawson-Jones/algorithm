class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> stk;

        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top(); stk.pop();
            res.push_back(root->val);
            root = root->right;
        }

        return res;
    }
};