/*
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

输入:
11110
11010
11000
00000
输出: 1
 */
#include <stdio.h>

void recursive(int x, int y, int rows, int cols, char **grid) {
    grid[x][y] = '0';
    if (x - 1 >= 0 && grid[x - 1][y] - '0')     recursive(x - 1, y, rows, cols, grid);
    if (x + 1 < rows && grid[x + 1][y] - '0')   recursive(x + 1, y, rows, cols, grid);
    if (y - 1 >= 0 && grid[x][y - 1] - '0')     recursive(x, y - 1, rows, cols, grid);
    if (y + 1 < cols && grid[x][y + 1] - '0')   recursive(x, y + 1, rows, cols, grid);
}

int numIslands(char **grid, int gridSize, const int *gridColSize) {
    if (!gridSize) return 0;
    int rows = gridSize;
    int cols = gridColSize[0];
    int island_nums = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int test = grid[i][j];
            if (!(grid[i][j] - '0')) continue;
            island_nums++;
            recursive(i, j, rows, cols, grid);
        }
    }
    return island_nums;
}
