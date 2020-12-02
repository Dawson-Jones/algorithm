/*
给你链表的头结点 head，请将其按 升序 排列并返回 排序后的链表。

在 O(nlogn) 时间复杂度和常数级空间复杂度下，对链表进行排序
*/

#include "utils/utilsLib.h"

struct ListNode *mergeList(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode temp;
    struct ListNode *cursor = &temp;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            cursor->next = l1;
            l1 = l1->next;
        } else {
            cursor->next = l2;
            l2 = l2->next;
        }
        cursor = cursor->next;
    }

    cursor->next = l1 ? l1 : l2;
    return temp.next;
}

struct ListNode *sortList(struct ListNode *head) {
    if (!head || !head->next) return head;

    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;

    return mergeList(sortList(head), sortList(fast));
}

int main() {
    struct ListNode l4 = {3, 0};
    struct ListNode l3 = {1, &l4};
    struct ListNode l2 = {2, &l3};
    struct ListNode l1 = {4, &l2};
    struct ListNode *res = sortList(&l1);
    while (res) {
        printf("res: %d\n", res->val);
        res = res->next;
    }
    return 0;
}