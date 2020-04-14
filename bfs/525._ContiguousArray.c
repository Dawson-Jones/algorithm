/*
 * 给定一个二进制数组, 找到含有"相同数量"的 0 和 1 的最长连续子数组（的长度）。

输入: [0,1]
输出: 2
说明: [0, 1] 是具有相同数量0和1的最长连续子数组。

输入: [0,1,0]
输出: 2
说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
 */

#include <stdio.h>
#include <memory.h>

int findMaxLength(const int *nums, int numsSize) {
    int arr[2 * numsSize + 1];
    // 这个只能初始化 char 类型, 所以每一个 arr 中的元素实际上被初始化成了
    // 4个char: [1 1 1 1 1 1 1 0] 类型, 可参考下面:
    // char x[4] = {-2, -2, -2, -2};
    // int *xx = (int *)x;  
    // printf("char to int: %d\n", *xx); // char to int: -16843010

    memset(arr, -2, sizeof(arr));  // -16843010
    arr[numsSize] = -1;  // 让第一个数是 0, 不然的话会错开..
    int maxLen = 0;
    int count = 0;
    for (int i = 0; i < numsSize; ++i) {
        count += nums[i] * 2 - 1;
        if (arr[count + numsSize] >= -1) {
            maxLen = i - arr[count + numsSize] > maxLen ? i - arr[count + numsSize] : maxLen;
        } else {
            arr[count + numsSize] = i;
        }
    }
    return maxLen;
}

int main() {
    int arr[] = {0, 1};
    int res = findMaxLength(arr, sizeof(arr) / sizeof(int));
    printf("res: %d", res);

}