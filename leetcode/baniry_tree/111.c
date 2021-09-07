 struct TreeNode_depth {
    struct TreeNode *tn;
    int depth;
};

int minDepth(struct TreeNode *root) {
    if (!root) return 0;
    
    struct TreeNode_depth *tmp = (struct TreeNode_depth *) alloca(sizeof(struct TreeNode_depth));
    tmp->tn = root;
    tmp->depth = 1;
    struct TreeNode_depth *queue[10000] = {tmp};
    int st = 0;
    int ed = 1;

    while (st < ed) {
        struct TreeNode_depth *cur = queue[st];
        struct TreeNode *cur_tn = cur->tn;
        int depth = cur->depth;

        if (!(cur_tn->left || cur_tn->right))
            return cur->depth;
        
        
        if (cur_tn->left) {        
            tmp = (struct TreeNode_depth *) alloca(sizeof(struct TreeNode_depth));

            tmp->tn = cur_tn->left;
            tmp->depth = depth + 1;
            queue[ed++] = tmp;
        }
        if (cur_tn->right) {
            tmp = (struct TreeNode_depth *) alloca(sizeof(struct TreeNode_depth));

            tmp->tn = cur_tn->right;
            tmp->depth = depth + 1;
            queue[ed++] = tmp;
        }
        
        st++;
    }
    
    return 0;
}