// 用递归做在遍历的时候就可以改变链表了
// 而解法 1 是存下了中序遍历的结果
class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        if (!root) 
            return nullptr;
        
        dfs(root);
        head->left = pre;
        pre->right = head;
        
        return head;
    }

private:
    Node *pre, *head;

    void dfs(Node *cur) {
        if (!cur) 
            return;
        
        dfs(cur->left);
        if (pre) 
            pre->right = cur;
        else 
            head = cur;
        
        cur->left = pre;
        pre = cur;
        
        dfs(cur->right);
    }
};