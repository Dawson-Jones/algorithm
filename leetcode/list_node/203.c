struct ListNode* removeElements(struct ListNode* head, int val){
    if (!head) return head;

    struct ListNode *pre = calloc(1, sizeof(struct ListNode));
    struct ListNode *vertex = pre;

    while (head) {
        if (head->val != val) {
            pre->next = head;
            pre = pre->next;
        }
        head = head->next;
    }

    pre->next = NULL;
    return vertex->next;
}