struct ListNode* swapPairs(struct ListNode* head){
    if (!(head && head->next))
        return head;
    
    struct ListNode *vertex = head->next;
    head->next = swapPairs(vertex->next);
    vertex->next = head;
    return vertex;
}
