/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
*/

#include "utils/utilsLib.h"
void moveZeroes(int* nums, int numsSize){
    int nz_p = 0;   // 非零指针
    int z_p = 0;    // 零指针

    int temp;
    while (nz_p < numsSize) {
        if (nums[nz_p]) {
            // swap
            temp = nums[z_p];
            nums[z_p] = nums[nz_p];
            nums[nz_p] = temp;

            z_p++;
        }
        nz_p++;
    }
}