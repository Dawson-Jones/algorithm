class Solution {
private:
    unordered_map<Node *, Node *> node_map;
public:
    Node *copyRandomList(Node *head) {
        Node *cp_head = new Node(0);
        Node *anchor = cp_head;
        Node *pin = head;
        Node *tmp;
        while (head) {
            tmp = new Node(head->val);
            node_map[head] = tmp;
            cp_head = cp_head->next = tmp;
            head = head->next;
        }
        
        head = pin;
        cp_head = anchor->next;
        while (head) {
            cp_head->random = node_map[head->random];
            head = head->next;
            cp_head = cp_head->next;
        }
        
        return anchor->next;
    }
};