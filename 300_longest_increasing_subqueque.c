/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLIS(int* nums, int numsSize){
    if (numsSize==0) return 0;
    int dp[numsSize];
    for(int i=0;i<numsSize;i++)
        dp[i] = 1;

    int longest = 0;
    for(int i=0;i<numsSize;i++){
        for(int j=0;j<i;j++)
            if(nums[j]<nums[i])
                dp[i] = dp[i]>dp[j]+1?dp[i]:dp[j]+1;
        longest = longest>dp[i]?longest:dp[i];
    }
    return longest;
}

int main(int argc, char const *argv[]){
    int nums[] = {10,9,2,5,3,7,101,18};
    int res = lengthOfLIS(nums, sizeof(nums)/sizeof(int));
    printf("res: %d\n", res);
    return 0;
}
