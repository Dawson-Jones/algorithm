class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q({root});
        TreeNode *cur;
        int n;
        while (!q.empty()) {
            n = q.size();
            for (int i = 0; i < n; ++i) {
                cur = q.front(); q.pop();
                if (cur->right)
                    q.push(cur->right);
                if (cur->left)
                    q.push(cur->left);
            }
        }
        return cur->val;
    }
};