/*
 * 链表的插入排序
 */
#include "utils/utilsLib.h"

struct ListNode *find_median(struct ListNode *left, struct ListNode *right, int flag) {
    struct ListNode *pre, *slow, *fast;
    pre = slow = fast = left;
    while (fast != right && fast->next != right) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (flag)
        pre->next = NULL;

    return slow;
}

struct ListNode *merge_listnode(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode tmp;
    struct ListNode *cur = &tmp;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur = cur->next = l1;
            l1 = l1->next;
        } else {
            cur = cur->next = l2;
            l2 = l2->next;
        }
    }

    cur->next = l1 ? l1 : l2;
    return tmp.next;
}

struct ListNode* sortList(struct ListNode* head){
    if (!(head && head->next)) return head;

    struct ListNode *mid = find_median(head, NULL, 1);
    return merge_listnode(sortList(head), sortList(mid));
}