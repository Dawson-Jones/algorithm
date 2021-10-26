/**
 * 
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。
 */

bool same(struct TreeNode *a, struct TreeNode *b) {
	// b is null, 这半边已经不需要再比较了
    if (b == NULL)
        return true;
	
	// b 不是 null, a 是 null, 直接返回false
    if (a == NULL)
        return false;

    if (a->val != b->val)
        return false;

    return same(a->left, b->left) && same(a->right, b->right);
}



bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
    if (A == NULL || B == NULL)
        return false;
    if (same(A, B))
        return true;
    
    return isSubStructure(A->left, B) || isSubStructure(A->right, B);
}