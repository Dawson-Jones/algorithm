/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/
#include "utils/utilsLib.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode node;
    struct ListNode *dummy = &node;
    struct ListNode *cursor = dummy;
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
    return dummy->next;
}