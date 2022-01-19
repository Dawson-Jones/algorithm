/**
 * 给定一个单链表 L 的头节点 head ，单链表 L 表示为：

 L0 → L1 → … → Ln-1 → Ln 
请将其重新排列后变为：

L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 */

struct ListNode *find_median(struct ListNode *left, struct ListNode *right) {
    struct ListNode *slow, *fast;
    slow = fast = left;
    while (fast != right && fast->next != right) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

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

void reorderList(struct ListNode* head){
    struct ListNode *mid = find_median(head, NULL);
    mid = reverse(mid);

    struct ListNode *pre = malloc(sizeof(struct ListNode));
    struct ListNode *h_n;
    while (head && mid) {
        h_n = head->next;
        pre->next = head;
        head->next = mid;
        pre = mid;
        mid = mid->next;
        head = h_n;
    }
    if (pre == pre->next)
        pre->next = NULL;
}