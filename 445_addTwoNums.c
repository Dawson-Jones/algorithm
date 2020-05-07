/*
两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。
将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 8 -> 0 -> 7
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


#include <stdio.h>
#include <stdlib.h>

void linkToStack(struct ListNode *root, int *stack, int *size) {
    while (root) {
        stack[(*size)++] = root->val;
        root = root->next;
    }
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    if (!l1->val) return l2;
    if (!l2->val) return l1;

    int stack1[100];
    int stack2[100];
    int stack1Size = 0;
    int stack2Size = 0;
    linkToStack(l1, stack1, &stack1Size);
    linkToStack(l2, stack2, &stack2Size);

    int carry = 0;
    struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));
    head->next = 0;

    while (stack1Size || stack2Size || carry) {
        int temp1 = 0, temp2 = 0;
        if (stack1Size)
            temp1 = stack1[--stack1Size];
        if (stack2Size)
            temp2 = stack2[--stack2Size];
        int mod = (temp1 + temp2 + carry) % 10;
        carry = (temp1 + temp2 + carry) / 10;

        // 头插
        struct ListNode *temp = (struct ListNode *) malloc(sizeof(struct ListNode));
        temp->val = mod;
        temp->next = head->next;
        head->next = temp;
    }
    struct ListNode *res = head->next;
    free(head);
    return res;
}

int main() {
    struct ListNode l14 = {3, 0};
    struct ListNode l13 = {4, &l14};
    struct ListNode l12 = {2, &l13};
    struct ListNode l11 = {7, &l12};

    struct ListNode l23 = {4, 0};
    struct ListNode l22 = {6, &l23};
    struct ListNode l21 = {5, &l22};
    struct ListNode *res = addTwoNumbers(&l11, &l21);

    struct ListNode *storage;
    while (res) {
        storage = res;
        printf("%d ", res->val);
        res = res->next;
        free(storage);
    }
    return 0;
}

