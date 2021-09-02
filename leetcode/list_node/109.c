
struct ListNode *find_middle(struct ListNode *left, struct ListNode *right) {
    struct ListNode *slow, *fast;
    slow = fast = left;

    while (fast != right && fast->next != right) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

struct TreeNode *build_binary_tree(struct ListNode *left, struct ListNode *right) {
    if (left == right) {
        return NULL;
    }
    
    struct ListNode *mid = find_middle(left, right);
    struct TreeNode *root = calloc(1, sizeof(struct TreeNode));
    root->val = mid->val;
    root->left = build_binary_tree(left, mid);
    root->right = build_binary_tree(mid->next, right);
    
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    return build_binary_tree(head, NULL);
}
