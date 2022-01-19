struct ListNode *oddEvenList(struct ListNode *head) {
    if (!head)
        return NULL;
    struct ListNode *odd = head;
    struct ListNode *even = head->next;
    struct ListNode *anchor = even;
    while (even && even->next) {
        odd = odd->next = odd->next->next;
        even = even->next = even->next->next;
    }

    odd->next = anchor;
    return head;
}