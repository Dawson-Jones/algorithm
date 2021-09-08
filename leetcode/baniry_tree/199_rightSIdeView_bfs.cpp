class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (!root)
            return res;

        res.push_back(root->val);

        queue<TreeNode *> q({root});
        TreeNode *cur;
        int n;

        while (!q.empty()) {
            n = q.size();
            for (int i = 0; i < n; ++i) {
                cur = q.front();
                q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            if (q.size())
                res.push_back(q.back()->val);
        }
        return res;
    }
};