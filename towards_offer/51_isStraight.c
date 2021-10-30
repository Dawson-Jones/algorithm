// 排序加遍历
int cmp(void *x, void *y) {
    return *(int *) x - *(int *) y;
}

bool isStraight(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int zero_nums = 0;
    int pre = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 0) {
            zero_nums++;
            continsue;
        }

        if (!pre) {
            pre = nums[i];
            continue;
        }

        int lack = nums[i] - pre - 1;
        pre = nums[i];
        if (lack < 0)
            return false;
        zero_nums -= lack;
        if (zero_nums < 0)
            return false;
    }

    return true;
}