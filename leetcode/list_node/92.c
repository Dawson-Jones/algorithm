#include <utils/utilsLib.h>

struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
    if (!(head && head->next)) return head;

    int i;
    struct ListNode *anchor = NULL;
    struct ListNode *pre = NULL;
    struct ListNode *top = head;

    for (i = 1; head; ++i) {
        if (i >= left) {
            break;
        }
        pre = head;
        head = head->next;
    }
    anchor = head;

    struct ListNode *tmp;
    struct ListNode *cur = pre;
    if (i >= right) {
        return top;
    }
    for (; head; ++i) {
        tmp = head->next;
        head->next = cur;
        cur = head;
        head = tmp;

        if (i >= right) {
            break;
        }
    }

    if (pre) {
        pre->next = cur;
        anchor->next = head;
        return top;
    }
    anchor->next = head;
    return cur;
}