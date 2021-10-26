struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode node;
    struct ListNode *dummy = &node;
    struct ListNode *cursor = dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cursor->next = l1;
            l1 = l1->next;
        } else {
            cursor->next = l2;
            l2 = l2->next;
        }
        cursor = cursor->next;
    }
    cursor->next = l1 ? l1 : l2;
    return dummy->next;
}