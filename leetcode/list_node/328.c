struct ListNode* oddEvenList(struct ListNode* head){
    if (!(head && head->next)) return head;
    struct ListNode *odd;
    struct ListNode *even;
    struct ListNode *anchor_o = odd = head;
    struct ListNode *anchor_e = even = head->next;

    while (even && even->next) {
        odd = odd->next = even->next;
        even = even->next = odd->next;
    }

    odd->next = anchor_e;
    return anchor_o;
}