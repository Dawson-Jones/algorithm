struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *pre = NULL;
    struct ListNode *cur = NULL;

    while (head) {
        cur = head;
        head = head->next;
        cur->next = pre;
        pre = cur;
    }

    return cur;
}