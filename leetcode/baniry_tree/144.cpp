class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> stk;

        while (root || !stk.empty()) {
            while (root) {
                res.push_back(root->val);
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top(); stk.pop();
            root = root->right;
        }

        return res;
    }
};