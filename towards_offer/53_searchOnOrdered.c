int binarySearch(int *nums, int numsSize, int target) {
    int l = 0;
    int r = numsSize - 1;
    int m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (nums[m] <= target)
            l = m + 1;
        else
            r = m - 1;
    }

    return l;
}

int search(int *nums, int numsSize, int target) {
    return binarySearch(nums, numsSize, target) - binarySearch(nums, numsSize,target-1);
}