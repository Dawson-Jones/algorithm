class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode *> q({root});
        TreeNode *cur;

        while (!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            for (int i = 0; i < n; ++i) {
                cur = q.front(); q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
                
                tmp.push_back(cur->val);
            }
            res.push_back(tmp);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};