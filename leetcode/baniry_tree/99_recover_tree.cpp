class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode *> stk;
        TreeNode *first, *second, *pre;
        first = second = pre = nullptr;

        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
                continue;
            }
            
            root = stk.top(); stk.pop();
            if (pre && pre->val > root->val) {
				if (!first)
					first = pre;

				second = root;
            }
            pre = root;
            root = root->right;
        }
        swap(first->val, second->val);
    }
};