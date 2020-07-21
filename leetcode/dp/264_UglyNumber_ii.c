/*
 * 编写一个程序，找出第 n 个丑数。

丑数就是质因数只包含 2, 3, 5 的正整数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 */

#include "utils/utilsLib.h"

int nthUglyNumber(int n) {
    int dp[n];
    dp[0] = 1;
    int p2, p3, p5;
    p2 = p3 = p5 = 0;

    int min3(int, int, int);
    for (int i = 1; i < n; ++i) {
        dp[i] = min3(dp[p2] * 2, dp[p3] * 3, dp[p5] * 5);
        if (dp[i] == (dp[p2] * 2)) p2++;
        if (dp[i] == (dp[p3] * 3)) p3++;
        if (dp[i] == (dp[p5] * 5)) p5++;
    }
    return dp[n-1];
}

int min3(int x, int y, int z) {
    x = x < y ? x : y;
    x = x < z ? x : z;
    return x;
}