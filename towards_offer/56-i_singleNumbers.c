int* singleNumbers(int* nums, int numsSize, int* returnSize){
    *returnSize = 2;
    int res = 0;
    for (int i = 0; i < numsSize; ++i) {
        res ^= nums[i];
    }
    
    // find the diff in res;
    res = res & ~(res - 1);
    
    int x = 0, y = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] & res)
            x ^= nums[i];
        else
            y ^= nums[i];
    }
    
    int *value = (int *)malloc(sizeof(int) * 2);
    value[0] = x;
    value[1] = y;
    return value;
}