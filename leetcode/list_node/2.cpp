class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode();
        ListNode *cur = res;

        int carry = 0;
        int sum;
        while (l1 || l2) {
            ListNode *temp = new ListNode();
            if (l1 && l2) {
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1) {
                sum = l1->val + carry;
                l1 = l1->next;
            } else {
                sum = l2->val + carry;
                l2 = l2->next;
            }

            temp->val = sum % 10;
            carry = sum / 10;
            cur->next = temp;
            cur = cur->next;
        }
        if (carry) {
            cur->next = new ListNode(carry);
        }
        return res->next;
    }
};