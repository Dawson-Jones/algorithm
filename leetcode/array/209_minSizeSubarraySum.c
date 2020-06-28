/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
 */
#include "../utils/utilsLib.h"

int minSubArrayLen(int s, int* nums, int numsSize){
    int min_num = INT32_MAX;
    int left = 0;
    int right = 0;
    int cur_total = 0;
    while (right <= numsSize) {
        if (cur_total < s) {
            if (right == numsSize) break;
            cur_total += nums[right++];
        } else {
            min_num = min_num < right - left ? min_num : right - left;
            cur_total -= nums[left++];
        }
    }
    return min_num == INT32_MAX ? 0 : min_num;
}

int main() {
    int s = 7;
    int nums[6] = {2,3,1,2,4,3};
    int res = minSubArrayLen(s, nums, 6);
    printf("res: %d\n", res);
}
