/*
给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

输入: 5
输出: [0,1,1,2,1,2]
*/

#include "utils/utilsLib.h"

int *countBits(int num, int *returnSize) {
    int *dp = (int *) malloc(sizeof(int) * (num + 1));
    *dp = 0;

    for (int i = 1; i <= num; ++i) {
        if (!(i % 2))
            dp[i] = dp[i/2];
        else
            dp[i] = dp[i-1] + 1;
    }
    *returnSize = num+1;
    return dp;
}

int main(){
    int return_size;
    int *dp = countBits(5, &return_size);
    for (int i = 0; i < return_size; ++i) {
        printf("%d ", dp[i]);
    }
    printf("\n");
}