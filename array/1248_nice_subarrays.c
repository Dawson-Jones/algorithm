/*
给你一个整数数组 nums 和一个整数 k。
如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。
请返回这个数组中「优美子数组」的数目。

输入：nums = [1,1,2,1,1], k = 3
输出：2
解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
*/

int numberOfSubarrays(int *nums, int numsSize, int k) {
    int odd[numsSize + 2];
    // 第一个写成-1 方便计算
    odd[0] = -1;

    int odd_total = 1;
    // 统计奇数的位置
    for (int i = 0; i < numsSize; ++i) {
        if ((nums[i] & 1) == 1) odd[odd_total++] = i;
    }

    // 最后一个写成 numsize 方便计算
    odd[odd_total++] = numsSize;

    // 奇数个数过少
    if (odd_total < k + 2) return 0;

    int res = 0;
    for (int j = 1; j <= odd_total - 1 - k; ++j) {
        res += ((odd[j] - odd[j - 1]) * (odd[j + k] - odd[j + k - 1]));
    }
    return res;
}