/**
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
 */

#include <stdio.h>

int numSquares(int n) {
    int dp[n + 1];

    for (int i = 0; i < n + 1; i++) {
        dp[i] = i;
        for (int j = 1; i - j * j >= 0; j++) {
            dp[i] = dp[i] < dp[i - j * j] + 1 ? dp[i] : dp[i - j * j] + 1;
        }
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    int num;
    printf("input a num you wanna\n");
    scanf("%d", &num);
    int res = numSquares(num);
    printf("counts: %d\n", res);
    return 0;
}
