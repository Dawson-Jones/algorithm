/*
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 */

#include "utils/utilsLib.h"

int maxSubArray(int *nums, int numsSize) {
    int res = *nums;
    int cur_max = *nums;
    for (int i = 1; i < numsSize; ++i) {
        res += nums[i];
        if (res < nums[i])
            res = nums[i];
        cur_max = cur_max > res ? cur_max : res;
    }
    return cur_max;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("res: %d\n", maxSubArray(nums, sizeof(nums) / sizeof(int)));
}