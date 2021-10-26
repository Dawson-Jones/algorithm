struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *fixA = headA;
    struct ListNode *fixB = headB;
    int flag = 0;
    while (headA != headB) {
        headA = headA->next ? headA->next : ({flag++; fixB;});
        headB = headB->next ? headB->next : ({flag++; fixA;});
        if (flag > 2)
            return NULL;
    }
    return headA;
}