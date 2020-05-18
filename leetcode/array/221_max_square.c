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
    int maxSide = 0;
    if (!matrixSize) return maxSide;
    int dp[matrixSize][*matrixColSize];

    for (int i = 0; i < matrixSize; ++i) {
        dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
        maxSide |= dp[i][0];
    }

    for (int j = 0; j < *matrixColSize; ++j) {
        dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
        maxSide |= dp[0][j];
    }

    int myMin(int, int, int);
    for (int i = 1; i < matrixSize; ++i) {
        for (int j = 1; j < *matrixColSize; ++j) {
            if (matrix[i][j] == '0') dp[i][j] = 0;
            else {
                dp[i][j] = myMin(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1;
                maxSide = maxSide > dp[i][j] ? maxSide : dp[i][j];
            }
        }
    }
    return maxSide * maxSide;
}

int myMin(int a, int b, int c) {
    a = a < b ? a : b;
    a = a < c ? a : c;
    return a;
}
