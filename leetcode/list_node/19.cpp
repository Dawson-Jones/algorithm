class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *slow, *fast, *pre;
        slow = fast = head;
        pre = dummy;
        for (int i = 0; i < n + 1; ++i) {
            fast = fast->next;
        }

        while (fast) {
            pre = pre->next;
            slow = slow->next;
            fast = fast->next;
        }

        pre->next = slow->next;
        return dummy->next;
    }
};