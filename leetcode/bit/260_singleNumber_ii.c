int *singleNumber(int *nums, int numsSize, int *returnSize) {
    long res = 0;
    *returnSize = 2;

    for (int i = 0; i < numsSize; ++i)
        res ^= nums[i];

    long diff = res & ~(res - 1);
    int *ans = calloc(2, sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] & diff) {
            ans[0] ^= nums[i];
        }
    }

    ans[1] = res ^ ans[0];
    return ans;
}