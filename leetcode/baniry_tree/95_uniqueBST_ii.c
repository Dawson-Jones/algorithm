/*
 * Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
 *
Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */

#include "utils/utilsLib.h"

struct TreeNode **generateTrees(int n, int *returnSize) {
    struct TreeNode ***dp = (struct TreeNode ***) malloc(sizeof(struct TreeNode **) * (n + 1));
    dp[0] = NULL;
    int dp_num[n + 1];
    memset(dp_num, 0, sizeof(dp_num));
    dp_num[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp_num[i] += dp_num[j] * dp_num[i - j - 1];
        }

        struct TreeNode **cur_arr = (struct TreeNode **) malloc(sizeof(struct TreeNode *) * dp_num[i]);
        // vertex -> i
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < dp_num[k]; ++k) {
                for (int l = 0; l < ; ++l) {
                    
                }
            }
        }
    }
}