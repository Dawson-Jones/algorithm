struct ListNode *reverse(struct ListNode *head) {
    struct ListNode *tmp;
    struct ListNode *pre = NULL;

    while (head) {
        tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
    }

    return pre;
}

struct ListNode *reverseKGroup(struct ListNode* head, int k){
    if (!head) return head;

    int i = 1;
    struct ListNode *cur = head;
    while (cur) {
        cur = cur->next;
        i++;

        if (i == k)
            break;
    }
    
    if (!cur)
        return head;

    
    struct ListNode *next;
    next = cur->next;
    cur->next = NULL;
    struct ListNode *reversed = reverse(head);
    head->next = reverseKGroup(next, k);
    return reversed;
}