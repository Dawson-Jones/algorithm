#include "utils/utilsLib.h"

int cmp(const void *x, const void *y) {
    return *(int *) x > *(int *) y;
}

void nextPermutation(int *nums, int numsSize) {
    int behind = nums[numsSize - 1];
    int cur;

    for (int i = numsSize - 1; i >= 0; --i) {
        if ((cur = nums[i]) >= behind) {
            behind = cur;
            continue;
        }

        qsort(nums + i + 1, numsSize - i - 1, sizeof(int), cmp);
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[j] > cur) {
                nums[i] = nums[j];
                nums[j] = cur;
                return;
            }
        }
    }

    qsort(nums, numsSize, sizeof(int), cmp);
}

int main() {
    int nums[] = {1, 3, 2};
//    qsort(nums, 3, sizeof(int), cmp);
    nextPermutation(nums, 3);
    for (int i = 0; i < sizeof(nums) / sizeof(int); ++i) {
        printf("res: %d\n", nums[i]);
    }
}