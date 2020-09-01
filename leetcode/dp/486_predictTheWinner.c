/*
 *给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，然后玩家 1 拿，…… 。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。
给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。


输入：[1, 5, 2]
输出：False
解释：一开始，玩家1可以从1和2中进行选择。
如果他选择 2（或者 1 ），那么玩家 2 可以从 1（或者 2 ）和 5 中进行选择。如果玩家 2 选择了 5 ，那么玩家 1 则只剩下 1（或者 2 ）可选。
所以，玩家 1 的最终分数为 1 + 2 = 3，而玩家 2 为 5 。
因此，玩家 1 永远不会成为赢家，返回 False 。

输入：[1, 5, 233, 7]
输出：True
解释：玩家 1 一开始选择 1 。然后玩家 2 必须从 5 和 7 中进行选择。无论玩家 2 选择了哪个，玩家 1 都可以选择 233 。
     最终，玩家 1（234 分）比玩家 2（12 分）获得更多的分数，所以返回 True，表示玩家 1 可以成为赢家。
 */
#include "utils/utilsLib.h"

// 复杂度 2 的 n 次方
int get_score(int *nums, int left, int right);

bool PredictTheWinnerRecur(int* nums, int numsSize){
    return get_score(nums, 0, numsSize-1) >= 0;
}

int get_score(int *nums, int left, int right) {
    if (left == right) return nums[left];   // 只剩一个可选了， 递归的结尾

    // 为什么要减，是因为下次就是对面拿的最大值了，我们希望对面拿的足够小
    int pick_left = nums[left] - get_score(nums, left+1, right);
    int pick_right = nums[right] - get_score(nums, left, right-1);

    return fmax(pick_left, pick_right);
}

// dp 不好理解
bool PredictTheWinner(int* nums, int numsSize){
    // dp[i][j] 表示 从 i 到 j 可以选到的最大值差值
    int dp[numsSize][numsSize];

    for (int i = 0; i < numsSize; ++i) {
        dp[i][i] = nums[i];     // 从 i 到 i 只有一个可选就是自己
    }

    // 转移方程 dp[i][j] = max(num[i] - dp[i+1][j], nums[j] - dp[i][j-1])
    // 方程的意思是， 选择了一个数， 使得剩下的值拿到的最小
    // dp[i+1][j] 和 dp[i][j-1] 要比 dp[i][j] 提前知道
    for (int i = numsSize-2; i >= 0; --i) {
        for (int j = i+1; j < numsSize; ++j) {
            dp[i][j] = fmax(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
        }
    }

    return dp[0][numsSize-1] >= 0;
}
