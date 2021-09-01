struct ListNode* deleteDuplicates(struct ListNode* head){
    if (!head->next) return head;
    struct ListNode tmp_dummy = {0};

    struct ListNode *node;
    struct ListNode *cursor = head;
    struct ListNode *dummy = &tmp_dummy;
    struct ListNode *vertex = dummy;

    while ((node = cursor) != NULL) {
        cursor = cursor->next;
        if (cursor && node->val == cursor->val) {
            do {
                cursor = cursor->next;
            } while (cursor && cursor->val == node->val);

            continue;
        }

        dummy->next = node;
        dummy = dummy->next;
    }
    dummy->next = NULL;
    return vertex->next;
}