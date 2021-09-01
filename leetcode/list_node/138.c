struct Node* copyRandomList(struct Node* head) {
    if (!head)
        return NULL;
    
    // copy next node
    for (struct Node *node = head; node; node = node->next->next) {
        struct Node *new_node = malloc(sizeof(struct Node));
        new_node->val = node->val;
        new_node->next = node->next;
        node->next = new_node;
    }

    // point to random node
    for (struct Node *node = head; node; node = node->next->next) {
        struct Node *new_node = node->next;
        new_node->random = node->random ? node->random->next : NULL;
    }
    
    // separate
    struct Node *new_head = head->next;
    for (struct Node *node = head; node; node = node->next) {
        struct Node *new_node = node->next;
        node->next = node->next->next;
        new_node->next = new_node->next ? new_node->next->next : NULL;
    }
    
    return new_head;
}