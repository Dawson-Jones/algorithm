#include "utils/utilsLib.h"

/*
 * 一个长度为n-1的递增排序数组中的所有数字都是唯一的，
 * 并且每个数字都在范围0～n-1之内。
 * 在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

输入: [0,1,3,4]
输出: 2

输入: [0,1,2,4,5,6,7,8,9]
输出: 3
 * */

int recur(int *nums, int start, int ed);

int missingNumber(int *nums, int numsSize) {
    return recur(nums, 0, numsSize);
}

int recur(int *nums, int st, int ed) {
    if (st >= ed) { return st; }

    int mid = (ed + st) / 2;
    if (nums[mid] == mid) {
        return recur(nums, mid + 1, ed);
    } else {
        return recur(nums, st, mid);
    }
}

int main() {
    int nums[] = {0,1,2,3,4,5,7,8,9};
    printf("res: %d", missingNumber(nums, sizeof(nums) / sizeof(int)));
    return 0;
}