/*
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

示例 1:
给定的树 s:

     3
    / \
   4   5
  / \
 1   2
给定的树 t：

   4
  / \
 1   2
返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。
*/

#include <stdio.h>
#include <stdbool.h>
#include "utils/utilsLib.h"

bool check(struct TreeNode *o, struct TreeNode *t) {
    if (!o && !t) return true;
    if ((o && !t) || (!o && t) || (o->val != t->val)) return false;
    return check(o->left, t->left) && check(o->right, t->right);
}

bool isSubtree(struct TreeNode *s, struct TreeNode *t) {
    if (!s) return false;
    return check(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}
