class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        int n;
        int flag = 1;
        queue<TreeNode *> q({root});
        struct TreeNode *cur;

        while (!q.empty()) {
            n = q.size();
            vector<int> tmp(n);
            for (int i = 0; i < n; ++i) {
                cur = q.front();
                q.pop();
                if (flag)
                    tmp[i] = cur->val;
                else
                    tmp[n - i - 1] = cur->val;
                
                if (cur->left) 
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            
            res.push_back(tmp);
            flag = !flag;
        }
        
        return res;
    }
};
