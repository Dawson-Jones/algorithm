class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *sm_fix = new ListNode;
        ListNode *lg_fix = new ListNode;
        ListNode *sm_cur = sm_fix;
        ListNode *lg_cur = lg_fix;

        while (head) {
            if (head->val < x) {
                sm_cur->next = head;
                sm_cur = sm_cur->next;
            } else {
                lg_cur->next = head;
                lg_cur = lg_cur->next;
            }            
            head = head->next;
        }
        
        sm_cur->next = lg_fix->next;
        lg_cur->next = nullptr;
        return sm_fix->next;
    }
};