#include <utils/utilsLib.h>


struct ListNode* rotateRight(struct ListNode* head, int k){
    if (!head) return head;

    int i;
    struct ListNode *h = head;
    for (i = 1; h->next != NULL; i++, h = h->next);
    h->next = head;

    k %= i;
    k = i - k;
    struct ListNode *pre = NULL;
    for (i = 0; i < k; ++i) {
        pre = head;
        head = head->next;
    }

    pre->next = NULL;
    return head;
}