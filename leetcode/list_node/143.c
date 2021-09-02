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
    struct ListNode *h_n, *m_n;
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