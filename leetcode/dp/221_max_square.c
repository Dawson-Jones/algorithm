/*
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

输入:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4
 */

int maximalSquare(char **matrix, int matrixSize, int *matrixColSize) {
    int max_side = 0;
    if (!matrixSize) return max_side;
    int dp[matrixSize][*matrixColSize];

    for (int i = 0; i < matrixSize; ++i) {
        dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
        max_side |= dp[i][0];
    }

    for (int j = 0; j < *matrixColSize; ++j) {
        dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
        max_side |= dp[0][j];
    }

    int min3(int, int, int);
    for (int i = 1; i < matrixSize; ++i) {
        for (int j = 1; j < *matrixColSize; ++j) {
            if (matrix[i][j] == '0') dp[i][j] = 0;
            else {
                dp[i][j] = min3(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1;
                max_side = max_side > dp[i][j] ? max_side : dp[i][j];
            }
        }
    }
    return max_side * max_side;
}

int min3(int a, int b, int c) {
    a = a < b ? a : b;
    a = a < c ? a : c;
    return a;
}
