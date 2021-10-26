class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<TreeNode *> q({root});
        TreeNode *cur_node;
        while (!q.empty()) {
            int cur_level_size = q.size();
            res.push_back(vector<int>());
            for (int i = 0; i < cur_level_size; ++i) {
                cur_node = q.front(); q.pop();
                res.back().push_back(cur_node->val);
                if (cur_node->left)
                    q.push(cur_node->left);
                if (cur_node->right)
                    q.push(cur_node->right);
            }
        }
        
        return res;
    }
};