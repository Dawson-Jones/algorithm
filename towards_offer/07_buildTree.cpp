// same as 105
class Solution {
private:
    unordered_map<int, int> inorder_value_idx;
    TreeNode *build_tree(vector<int> &preorder, vector<int> &inorder, int pre_l, int pre_r, int in_l, int in_r) {
        if (pre_l > pre_r)
            return nullptr;
        int pre_root_idx = pre_l;
        int in_root_idx = inorder_value_idx[preorder[pre_root_idx]];
        
        TreeNode *root = new TreeNode(preorder[pre_root_idx]);
        int left_size = in_root_idx - in_l;
        root->left = build_tree(preorder, inorder, pre_l + 1, pre_l + left_size, in_l, in_root_idx - 1);
        root->right = build_tree(preorder, inorder, pre_l + left_size + 1, pre_r, in_root_idx + 1, in_r);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            inorder_value_idx[inorder[i]] = i;
        }
        return build_tree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
}