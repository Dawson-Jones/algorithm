// same as leetcode 240
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (matrixSize == 0)
        return false;
        
    int cur;
    int row = matrixSize;
    int col = matrixColSize[0];
    int i = row - 1, j = 0;
    while (i >= 0 && j < col) {
        cur = matrix[i][j];
        if (cur > target)
            i--;
        else if (cur < target)
            j++;
        else
            return true;
    }
    return false;
}