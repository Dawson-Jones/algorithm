class Solution {
public:
    unordered_map<Node *, Node *> cache_node;
    
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        
        if (!cache_node.count(head)) {
            Node *new_head = new Node(head->val);
            cache_node[head] = new_head;
            new_head->next = copyRandomList(head->next);
            new_head->random = copyRandomList(head->random);
        }
        
        return cache_node[head];
    }
};