class Solution {
public:
    vector<int> res;

    void dfs(TreeNode *root, int depth) {
        if (!root)
            return;

        if (res.size() < depth)
            res.push_back(root->val);
        dfs(root->right, depth + 1);
        dfs(root->left, depth + 1);

    }

    vector<int> rightSideView(TreeNode *root) {
        dfs(root, 1);
        return res;
    }
};