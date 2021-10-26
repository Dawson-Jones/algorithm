// same as leetcode 53
int maxSubArray(int* nums, int numsSize){
    if (numsSize == 0)
        return 0;
    
    int cur_max = nums[0];
    int pre_sum = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        pre_sum += nums[i];
        if (nums[i] > pre_sum) {
            pre_sum = nums[i];
        }
        cur_max = cur_max > pre_sum ? cur_max : pre_sum;
    }
    
    return cur_max;
}