/*
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
每次只能向下或者向右移动一步。

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
*/

#include "utils/utilsLib.h"

int minPathSum(int** grid, int gridSize, int* gridColSize){
    for (int i = 1; i < gridSize; ++i)
        grid[i][0] += grid[i-1][0];
    for (int k = 1; k < gridColSize[0]; ++k)
        grid[0][k] += grid[0][k-1];

    for (int i = 1; i < gridSize; ++i) {
        for (int j = 1; j < gridColSize[i]; ++j) {
            grid[i][j] += (grid[i-1][j] < grid[i][j-1] ? grid[i-1][j] : grid[i][j-1]);
        }
    }

    return grid[gridSize-1][(*gridColSize)-1];
}

int main(){
    int row1[3] = {1,3,1};
    int row2[3] = {1,5,1};
    int row3[3] = {4,2,1};
    int col[3] = {3, 3,3};
    int *grid[3] = {row1, row2, row3};
    printf("res: %d", minPathSum(grid, 3, col));
}