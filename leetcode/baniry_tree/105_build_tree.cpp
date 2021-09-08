class Solution {
private:
    unordered_map<int, int> index;
public:
    TreeNode *my_build_tree(vector<int> &preorder, vector<int> &inorder,
                            int pre_idx_l, int pre_idx_r,
                            int in_idx_l, int in_idx_r) {
        if (pre_idx_l > pre_idx_r)
            return nullptr;

        int in_idx_root = index[preorder[pre_idx_l]];
        TreeNode *root = new TreeNode(preorder[pre_idx_l]);
        int left_tree_size = in_idx_root - in_idx_l;
        root->left = my_build_tree(preorder, inorder, pre_idx_l+1, pre_idx_l+left_tree_size, in_idx_l, in_idx_root-1);
        root->right = my_build_tree(preorder, inorder, pre_idx_l+left_tree_size+1, pre_idx_r, in_idx_root+1, in_idx_r);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int  n = inorder.size();

        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }

        return my_build_tree(preorder, inorder, 0, n-1, 0, n-1);
    }
};