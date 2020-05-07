/*
给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
*/

struct Node {
    int val;
    int numChildren;
    struct Node **children;
};

int maxDepth(struct Node *root) {
    if (!root) return 0;

    int max = 1;
    for (int i = 0; i < root->numChildren; ++i) {
        int cur = maxDepth(root->children[i]) + 1;
        max = max > cur ? max : cur;
    }
    return max;
}

