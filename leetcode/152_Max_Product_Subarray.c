#include "utils/utilsLib.h"

/*
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
 */

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int maxProduct(int *nums, int numsSize) {
    int maxF = nums[0], minF = nums[0], ans = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        int mx = maxF, mn = minF;
        maxF = max(max(mx * nums[i], nums[i]), mn * nums[i]);
        minF = min(min(mn * nums[i], nums[i]), mx * nums[i]);
        ans = max(maxF, ans);
    }
    return ans;
}


int main() {
    int test[] = {-2, 3, -4};
    int resmaxProduct(test,
    3);
}