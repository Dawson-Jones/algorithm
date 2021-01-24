#include "utils/utilsLib.h"

/*
升序排列的整数数组 nums 在预先未知的某个点上进行了旋转
例如， [0,1,2,4,5,6,7] 经旋转后可能变为 [4,5,6,7,0,1,2] ）。
请你在数组中搜索 target ，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。


输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4

输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1

输入：nums = [1], target = 0
输出：-1
 * */

int search(int *nums, int numsSize, int target) {
    int mid;
    int i = 0;
    int j = numsSize - 1;

    while (i < j) {
        mid = (i + j) / 2;
        if (target == nums[mid]) return mid;

        if (nums[i] <= nums[mid]) {
            if (target >= nums[i] && target < nums[mid]) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        } else {
            if (target > nums[mid] && target <= nums[j]) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
    }

    return nums[i] == target ? i : -1;
}

int main() {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    printf("res: %d\n", search(nums, sizeof(nums) / sizeof(int), 3));
    return 0;
}