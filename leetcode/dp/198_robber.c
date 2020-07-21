/*
不相邻子数组的最大值

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
*/
#include <stdio.h>

int rob(int *nums, int numsSize) {
    if (!numsSize) return 0;
    int prev = 0;
    int cur = *nums;
    
    int temp;
    for (int i = 1; i < numsSize; ++i) {
        temp = prev + nums[i];
        prev = cur;
        cur = temp > cur ? temp : cur;
    }
    return  cur;
}

int main() {
    int arr[] = {1, 2, 3, 1};
    int res = rob(arr, sizeof(arr) / sizeof(int));
    printf("%d\n", res);
}