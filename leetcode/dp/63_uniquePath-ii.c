/*
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

 输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
 */

#include <stdio.h>

int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize) {
    if (obstacleGrid[0][0]) return 0;
    unsigned int dp[obstacleGridSize][obstacleGridColSize[0]];
    dp[0][0] = 1;
    for (int i = 1; i < obstacleGridSize; ++i)
        dp[i][0] = obstacleGrid[i][0] ? 0 : dp[i - 1][0];

    for (int i = 1; i < obstacleGridColSize[0]; ++i)
        dp[0][i] = obstacleGrid[0][i] ? 0 : dp[0][i - 1];

    for (int i = 1; i < obstacleGridSize; ++i)
        for (int j = 1; j < obstacleGridColSize[0]; ++j)
            dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i - 1][j] + dp[i][j - 1];

    return dp[obstacleGridSize - 1][obstacleGridColSize[0] - 1];
}


int
main() {
    int temp[3] = {3,3,3};
    int l1[3] = {0, 0, 0};
    int l2[3] = {0, 1, 0};
    int l3[3] = {0, 0, 0};
    int *arr[3] = {l1, l2, l3};
    int res = uniquePathsWithObstacles(arr, 3, temp);
    printf("%d\n", res);
}
