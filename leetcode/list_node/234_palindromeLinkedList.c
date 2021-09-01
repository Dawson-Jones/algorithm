/*
判断一个链表是否为回文链表。
用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

输入: 1->2
输出: false

输入: 1->2->2->1
输出: true
*/

#include "utils/utilsLib.h"

struct ListNode *reverse(struct ListNode *head) {
    struct ListNode *tmp;
    struct ListNode *pre = NULL;

    while (head) {
        tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
    }
    
    return pre;
}

bool compare_listnode(struct ListNode *a, struct ListNode *b) {
    while (b) {
        if (a->val != b->val)
            return false;
        
        a = a->next;
        b = b->next;
    }
    
    return true;
}

bool isPalindrome(struct ListNode* head){
    if (!head || !head->next) return head;
    
    struct ListNode *slow, *fast;
    slow = fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    fast = slow;
//    slow->next = NULL;
    fast = reverse(fast);
    
    return compare_listnode(head, fast);
}


int main() {
    struct ListNode ln2 = {2, NULL};
    struct ListNode ln1 = {1, &ln2};
    printf("res: %d", isPalindrome(&ln1));
    return 0;
}