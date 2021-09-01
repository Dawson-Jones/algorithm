struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *cur_a = headA;
    struct ListNode *cur_b = headB;

    while (cur_a != cur_b) {
        cur_a = cur_a ? cur_a->next : headB;
        cur_b = cur_b ? cur_b->next : headA;
    }

    return cur_a;
}
