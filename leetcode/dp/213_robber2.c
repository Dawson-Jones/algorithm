/*
不相邻子数组的最大值, 且首尾连在一起

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
*/
#include <stdio.h>

int my_rob(int *nums, int numsSize) {
    int pre = 0;
    int cur = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        int temp = pre + nums[i] > cur ? pre + nums[i] : cur;
        pre = cur;
        cur = temp;
    }
    return cur;
}

int rob(int *nums, int numsSize) {
    if (!numsSize) return 0;
    if (numsSize == 1) return nums[0];
    int res1, res2;
    return (res1 = my_rob(nums, numsSize - 1)) > (res2 = my_rob(++nums, numsSize - 1)) ? res1 : res2;
}

int main() {
    int arr[] = {2, 3, 2};
    int res = rob(arr, sizeof(arr) / sizeof(int));
    printf("%d\n", res);
}