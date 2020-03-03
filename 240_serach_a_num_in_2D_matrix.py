# 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

# 每行的元素从左到右升序排列。
# 每列的元素从上到下升序排列。
import time


class Solution:
    def searchMatrix(self, matrix, target):
        if not matrix or not matrix[0]:
            return False
        rows = len(matrix)
        for i in range(rows):
            if matrix[i][i] == target:
                return True
            if matrix[i][i] > target:
                for j in matrix[:i]:
                    if j == target:
                        return True
                for j in range(i):
                    if matrix[i][j] == target:
                        return True
                return False
        return False

    def searchMatrix_1st(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix or not matrix[0]:
            return False
        for li in matrix:
            if li[0] > target:
                return False
            for i in li:
                if i > target:
                    break
                if i == target:
                    return True
        return False


if __name__ == '__main__':
    mat = [
        [1, 4, 7, 11, 15],
        [2, 5, 8, 12, 19],
        [3, 6, 9, 16, 22],
        [10, 13, 14, 17, 24],
        [18, 21, 23, 26, 30]
    ]

    st = time.perf_counter()
    print(Solution().searchMatrix(mat, 5))
    print(Solution().searchMatrix(mat, 20))
    print(time.perf_counter() - st)
    st = time.perf_counter()
    print(Solution().searchMatrix_1st(mat, 5))
    print(Solution().searchMatrix_1st(mat, 20))
    print(time.perf_counter() - st)
