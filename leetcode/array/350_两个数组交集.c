/*
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
*/

#include "utils/utilsLib.h"

int compare(const void *a, const void *b) { return *(int *) a > *(int *) b; }

int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    *returnSize = 0;
    int *rtn_list = (int *) malloc(sizeof(int) * nums1Size);
    int i = 0, j = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            rtn_list[(*returnSize)++] = nums1[i];
            i++;
            j++;
        }
    }

    return rtn_list;
}