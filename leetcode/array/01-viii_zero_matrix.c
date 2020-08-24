/*
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

输入：
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出：
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
*/

#include "utils/utilsLib.h"

void setZeroes(int **matrix, int matrixSize, int *matrixColSize) {
    int set0_row[matrixSize];
    int set0_col[*matrixColSize];
    memset(set0_row, 0, sizeof(set0_row));
    memset(set0_col, 0, sizeof(set0_col));

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < *matrixColSize; ++j) {
            if (!matrix[i][j]) {
                set0_row[i] = 1;
                set0_col[j] = 1;
            }
        }
    }
    for (int i = 0; i < matrixSize; ++i) {
        if (set0_row[i]) {
            for (int j = 0; j < *matrixColSize; ++j) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int j = 0; j < *matrixColSize; ++j) {
        if (set0_col[j]) {
            for (int i = 0; i < matrixSize; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
}