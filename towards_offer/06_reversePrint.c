struct ListNode *reverse_node(struct ListNode *head, int *size) {
    struct ListNode *pre = NULL;
    struct ListNode *cur;

    *size = 0;
    while (head) {
        cur = head;
        head = head->next;
        cur->next = pre;
        pre = cur;
        (*size)++;
    }

    return cur;
}

int *reversePrint(struct ListNode *head, int *returnSize) {
    if (!head) {
        *returnSize = 0;
        return NULL;
    }
    head = reverse_node(head, returnSize);
    int *res = (int *) malloc(sizeof(int) * *returnSize);

    int size = 0;
    while (head) {
        res[size++] = head->val;
        head = head->next;
    }
    return res;
}