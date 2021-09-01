struct ListNode *detectCycle(struct ListNode *head) {
    if (!head || !head->next)
        return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast && fast->next) {
                slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            fast = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }

    }
    
    return NULL;
}