/*
给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。

输入：[1,2,3,4,5,6]
输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
*/

#include<stdlib.h>
#include<stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head){
    int count = 0;
    struct ListNode* cur = head;
    while(cur!=NULL){
        count++;
        cur = cur->next;
    }
    int mid = count/2;
    while(mid){
        head = head->next;
        mid--;
    }
    return head;
}