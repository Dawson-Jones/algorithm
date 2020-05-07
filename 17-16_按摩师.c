/*
相邻的不能同时选，求最大值

输入： [1,2,3,1]
输出： 4
解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
*/

#include<stdio.h>

int massage(int* nums, int numsSize){
    if(!numsSize) return 0;
    if(numsSize==1) return nums[0];

    int dp[numsSize];
    // init array
    for(int i=0;i<numsSize;i++)
        dp[i] = 0;

    dp[0] = nums[0];
    dp[1] = nums[0]<nums[1]?nums[1]:nums[0];
    for(int i = 2; i<numsSize;i++){
        //select or no
        dp[i] = dp[i-2]+nums[i]>dp[i-1]?dp[i-2]+nums[i]:dp[i-1];
    }
    return dp[numsSize-1];
}

int main(int argc, char const *argv[]){
    int arr[] = {1,2,3,1};
    int res = massage(arr, 4);
    printf("res: %d\n", res);
    return 0;
}
