class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode *> q({root});
        TreeNode *cur;
        while (!q.empty()) {
            cur = q.front(); q.pop();
            res.push_back(cur->val);
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }

        return res;
    }
};