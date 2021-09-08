class Solution {
private:
    unordered_map<int, int> idx_map;
public:
    TreeNode *my_buildtree(vector<int> &inorder, vector<int> &postorder,
                           int in_idx_st, int in_idx_ed,
                           int post_idx_st, int post_idx_ed) {
        if (in_idx_st > in_idx_ed)
            return nullptr;

        int p_idx = idx_map[postorder[post_idx_ed]];
        int left_size = p_idx - in_idx_st;
        TreeNode *root = new TreeNode(postorder[post_idx_ed]);
        root->left = my_buildtree(inorder, postorder, in_idx_st, p_idx-1, post_idx_st, post_idx_st+left_size-1);
        root->right = my_buildtree(inorder, postorder, p_idx+1, in_idx_ed, post_idx_st+left_size, post_idx_ed-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i)
            idx_map[inorder[i]] = i;
        return my_buildtree(inorder, postorder, 0, n-1, 0, n-1);
    }
};