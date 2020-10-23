/*
判断一个链表是否为回文链表。
用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

输入: 1->2
输出: false

输入: 1->2->2->1
输出: true
*/

#include "utils/utilsLib.h"

bool isPalindrome(struct ListNode* head){
    if (!head) return true;
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reversal the second half part of list node
    struct ListNode *head2 = slow->next;
    slow->next = NULL;
    struct ListNode *follower = NULL;
    struct ListNode *temp;
    while (head2) {
        temp = head2;
        head2 = head2->next;
        temp->next = follower;
        follower = temp;
    } // follower is vertex

    // compare this two list node
    while (follower) {
        if (head->val != follower->val) {
            return false;
        }
        head = head->next;
        follower = follower->next;
    }

    return true;
}

int main() {
    struct ListNode ln2 = {2, NULL};
    struct ListNode ln1 = {1, &ln2};
    printf("res: %d", isPalindrome(&ln1));
    return 0;
}