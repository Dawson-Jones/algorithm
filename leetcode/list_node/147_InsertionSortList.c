/*
 * 链表的插入排序
 */
#include "utils/utilsLib.h"

struct ListNode* insertionSortList(struct ListNode* head){
    if (!head) return head;
    struct ListNode *cursor1 = head->next;
    head->next = NULL;
    struct ListNode *current_node;

    while (cursor1) {
        current_node = cursor1;
        cursor1 = cursor1->next;

        if (current_node->val < head->val) {
            current_node->next = head;
            head = current_node;
            continue;
        }

        struct ListNode *cursor2 = head;
        bool flag = 0;
        while (cursor2->next) {
            if (current_node->val < cursor2->next->val) {
                struct ListNode *temp = cursor2->next;
                cursor2->next = current_node;
                current_node->next = temp;
                flag = 1;
                break;
            }
            cursor2 = cursor2->next;
        }

        if (!flag) {
            cursor2->next = current_node;
            current_node->next = NULL;
        }
    }

    return head;
}