/*
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

给定三角形：
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 */
#include "utils/utilsLib.h"

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize) {
    int min_path[triangleSize];

    int x, y;
    min_path[0] = triangle[0][0];
    for (int i = 1; i < triangleSize; ++i) {
        // 填最右边
        min_path[i] = triangle[i][i] + min_path[i - 1];

        // 中间
        for (int j = i - 1; j > 0; --j) {
            x = min_path[j - 1];
            y = min_path[j];
            min_path[j] = triangle[i][j] + (x < y ? x : y);
        }
        // 填最左边
        min_path[0] += triangle[i][0];
    }

    int res = INT32_MAX;
    for (int i = 0; i < triangleSize; ++i) {
        res = res < min_path[i] ? res : min_path[i];
    }
    return res;
}

int main() {
    int col1[1] = {-1};
//    int col1[1] = {2};
//    int col2[2] = {3, 4};
    int col2[2] = {-2, -3};
    int col3[3] = {5, 6, 7};
    int col4[4] = {4, 1, 8, 3};
//    int triangleColSize[4] = {1, 2, 3, 4};
    int triangleColSize[2] = {1, 2};
//    int *triangle[4] = {col1, col2, col3, col4};
    int *triangle[4] = {col1, col2};
    printf("res: %d\n", minimumTotal(triangle, 2, triangleColSize));
}