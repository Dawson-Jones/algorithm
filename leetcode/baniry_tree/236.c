// 本质上和上面一种是一样的, 上面的更简洁, 但是难理解

#include "utils/utilsLib.h"

bool recursive(struct TreeNode *cur, int p, int q, struct TreeNode **res) {
    if (!cur) return false;
    bool l_son = recursive(cur->left, p, q, res);
    bool r_son = recursive(cur->right, p, q, res);
    if ((l_son && r_son) || ((l_son || r_son) && (cur->val == p || cur->val == q))) {
        *res = cur;
    }
    return l_son || r_son || cur->val == p || cur->val == q;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode **res = &root;  // 必须赋一个值
    recursive(root, p->val, q->val, res);
    return *res;
}

