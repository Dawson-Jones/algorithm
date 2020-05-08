/*
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

输入: [1,2,3,4]
输出: [24,12,8,6]
 
不要使用除法，且在 O(n) 时间复杂度内完成此题。因为 0 会失效
*/

#include <stdlib.h>

int *productExceptSelf(const int *nums, int numsSize, int *returnSize) {
    *returnSize = numsSize;
    int *res = (int *) malloc(numsSize * sizeof(int));
    if (!res) exit(1);
    int k = 1;
    for (int i = 0; i < numsSize; ++i) {
        res[i] = k;
        k *= nums[i];
    }

    k = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        res[i] *= k;
        k *= nums[i];
    }
    return res;
}