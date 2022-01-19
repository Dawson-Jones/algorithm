class Solution {
public:
    Node *flatten(Node *head) {
        Node *cur = head;
        stack<Node *> stk;

        while (cur) {
            if (cur->child) {
                if (cur->next) {
                    stk.push(cur->next);
                    cur->next->prev = nullptr;
                }
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
            }

            if (!(cur->next || stk.empty())) {
                cur->next = stk.top();
                stk.top()->prev = cur;
                stk.pop();
            }
            cur = cur->next;
        }

        return head;
    }
};