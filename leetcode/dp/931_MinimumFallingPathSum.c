/*
给定一个方形整数数组 A，我们想要得到通过 A 的下降路径的最小和。
下降路径可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列。

输入：[[1,2,3],
      [4,5,6],
      [7,8,9]]
输出：12

和最小的下降路径是 [1,4,7]，所以答案是 12。
*/


#include "utils/utilsLib.h"

int min2(int x, int y) {
    return x < y ? x : y;
}

int min3(int x, int y, int z) {
    return min2(min2(x, y), z);
}

int minFallingPathSum(int** A, int ASize, int* AColSize){
    int col_size = *AColSize;
    int dp[ASize][col_size];
    for (int i = 0; i < col_size; ++i) {
        dp[0][i] = A[0][i];
    }

    for (int i = 1; i < ASize; ++i) {
        for (int j = 0; j < col_size; ++j) {
            if (!j) {
                dp[i][j] = A[i][j] + min2(dp[i-1][j], dp[i-1][j+1]);
            } else if (j == col_size-1) {
                dp[i][j] = A[i][j] + min2(dp[i-1][j], dp[i-1][j-1]);
            } else {
                dp[i][j] = A[i][j] + min3(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]);
            }
        }
    }

    int res = dp[ASize-1][0];
    for (int k = 1; k < col_size; ++k) {
        res = min2(res, dp[ASize-1][k]);
    }
    return res;
}

int main() {
    int row1[3] = {1, 2, 3};
    int row2[3] = {4, 5, 6};
    int row3[3] = {7, 8, 9};
    int col[3] = {3, 3, 3};
    int *A[3] = {row1, row2, row3};
    printf("res: %d\n", minFallingPathSum(A, 3, col));
}