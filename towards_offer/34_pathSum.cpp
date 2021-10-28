class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> tmp;
        if (!root)
            return res;
        
        helper(root, tmp, target);
        return res;
    }
private:
    int sum_of_eles(vector<int> &arr) {
        int res = 0;
        for (int x: arr) {
            res += x;
        }
        return res;
    }
    void helper(TreeNode *root, vector<int> &cur_arr, int target) {
        cur_arr.push_back(root->val);
        if (!root->left && !root->right) {
            if (sum_of_eles(cur_arr) == target) {
                res.push_back(cur_arr);
            }
            cur_arr.pop_back();
            return;
        }
        if (root->left)
            helper(root->left, cur_arr, target);
        if (root->right)
            helper(root->right, cur_arr, target);
        cur_arr.pop_back();
    }
};