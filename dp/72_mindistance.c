/*
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
 */

#include <stdio.h>
#include <string.h>

int min(n1, n2, n3) {
    int res = n1;
    res = res < n2 ? res : n2;
    res = res < n3 ? res : n3;
    return res;
}

int minDistance(char *word1, char *word2) {
    int n1 = strlen(word1);
    int n2 = strlen(word2);
    int dp[n1 + 1][n2 + 1];
    dp[0][0] = 0;

    // 第一行
    for (int j = 1; j < n2 + 1; ++j) {
        dp[0][j] = dp[0][j - 1] + 1;
    }
    // 第一列
    for (int i = 1; i < n1 + 1; ++i) {
        dp[i][0] = dp[i - 1][0] + 1;
    }
    for (int i = 1; i < n1 + 1; ++i) {
        for (int j = 1; j < n2 + 1; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // dp[i-1][j-1]     替换操作
                // dp[i-1][j]       word1 的删除操作
                // dp[i][j-1]       word1 的插入操作, 和word2 的删除操作是等价的
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
            }
        }
    }

    return dp[n1][n2];
}

int
main(int argc, char const *argv[]) {
    char *word1 = "horse";
    char *word2 = "ros";
    int res = minDistance(word1, word2);
    printf("res: %d\n", res);
    return 0;
}
