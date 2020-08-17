/*
给定一个整数类型的数组 nums，请编写一个能够返回数组 “中心索引” 的方法。

中心索引：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。

如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。

输入：
nums = [1, 7, 3, 6, 5, 6]
输出：3
解释：
索引 3 (nums[3] = 6) 的左侧数之和 (1 + 7 + 3 = 11)，与右侧数之和 (5 + 6 = 11) 相等。
同时, 3 也是第一个符合要求的中心索引。
 */
#include "utils/utilsLib.h"

int pivotIndex(int* nums, int numsSize){
    if (numsSize < 2) return -1;
    int total = 0;
    for (int i = 1; i < numsSize; ++i)
        total += nums[i];

    int left = 0;
    int index = 0;
    while (!(left == total || index == numsSize-1)) {
        left += nums[index++];
        total -= nums[index];
    }

    return left == total ? index : -1;
}

int main() {
    int nums[] = {-1,-1,-1,0,1,1};
    printf("res: %d", pivotIndex(nums, sizeof(nums)));
}