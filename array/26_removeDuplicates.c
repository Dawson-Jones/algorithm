/*
给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/

#include<stdio.h>

int removeDuplicates(int *nums, int numsSize) {
    if (numsSize <= 1) return numsSize;
    int slow = 0;
    int fast = 1;
    while (fast < numsSize) {
        if (nums[slow] != nums[fast])
            nums[++slow] = nums[fast];
        fast++;
    }
    return ++slow;
}

int main(int argc, char const *argv[]) {
    int arr[12] = {1, 2, 2, 3, 3, 4, 4, 4, 6, 8, 8, 9};
    int res = removeDuplicates(arr, 12);
    for (int i = 0; i < res; i++)
        printf("%d\n", arr[i]);
    return 0;
}
