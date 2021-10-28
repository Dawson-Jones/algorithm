/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        if (!root)
            return nullptr;
        stack<Node *> stk;
        vector<Node *> arr;
        
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top(); stk.pop();
            arr.push_back(root);
            root = root->right;
        }
        
        
        int p, n;
        for (int i = 0; i < arr.size(); ++i) {
            n = (i + 1) % arr.size();
            p = (i + arr.size() - 1) % arr.size();
            // cout << p << " " << n << endl;
            arr[i]->left = arr[p];
            arr[i]->right = arr[n];
        }
        return arr[0];
    }
};