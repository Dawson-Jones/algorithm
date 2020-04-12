/*
一个数组 nums 和一个值 val
 原地移除所有数值等于 val 的元素，并返回移除后数组的新长度。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

给定 nums = [3,2,2,3], val = 3,
函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
 */


#include <stdio.h>

int removeElement(int *nums, int numsSize, int val) {
    if (numsSize == 0) return 0;
    int lastIndex = numsSize - 1;
    for (int i = 0; i <= lastIndex; ++i) {
        if (nums[i] == val) {
            while (lastIndex >= i && nums[lastIndex--] == val);
            nums[i] = nums[lastIndex + 1];
        }
    }
    return lastIndex + 1;
}

int main() {
    int nums[] = {
            0, 1, 2, 2, 3, 0, 4, 2
    };
    int val = 2;
    int res = removeElement(nums, sizeof(nums) / sizeof(int), val);

    for (int i = 0; nums[i] != val; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    printf("total count of nums: %d", res);
    return 0;
}