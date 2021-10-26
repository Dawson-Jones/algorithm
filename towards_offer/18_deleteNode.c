struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode node;
    struct ListNode *dummy = &node;
    dummy->next = head;
    struct ListNode *pre = dummy;
    while (head) {
        if (head->val == val) {
            pre->next = head->next;
        }
        pre = head;
        head = head->next;
    }
    return dummy->next;
}