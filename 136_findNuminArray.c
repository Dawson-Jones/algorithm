/**
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

输入: [2,2,1]
输出: 1

输入: [4,1,2,1,2]
输出: 4
*/

#include<stdio.h>

int singleNumber(int *nums, int numsSize) {
    int res = 0;
    for (int i = 0; i < numsSize; i++)
        res ^= nums[i];
    return res;
}

int main() {
    int array[6] = {4, 1, 2, 1, 2};
    int res = singleNumber(array, 6);
    printf("res: %d\n", res);
    return 0;
}
