struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode *slow;
    struct ListNode *fast = head;
    for (int i = 0; i < k; ++i) {
        fast = fast->next;
    }
    slow = head;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}