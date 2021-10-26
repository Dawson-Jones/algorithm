// 和快排一样的思路
int* exchange(int* nums, int numsSize, int* returnSize){
    int even_st, even_ed, i, tmp;
    *returnSize = numsSize;
    for (i = 0; i < numsSize && nums[i] % 2; ++i);
    even_st = even_ed = i++;
    
    for (; i < numsSize; ++i) {
        if (nums[i] % 2) {
          tmp = nums[even_st];
          nums[even_st] = nums[i];
          nums[i] = tmp;
          even_st++;
        }
        even_ed++;
    }
    
    return nums;
}