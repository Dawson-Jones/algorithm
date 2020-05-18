#include "utils/utilsLib.h"

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *top = (struct ListNode *) malloc(sizeof(struct ListNode));
    if (!top) exit(1);
    struct ListNode *cur;
    cur = top;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    cur = top->next;
    free(top);
    return cur;
}
