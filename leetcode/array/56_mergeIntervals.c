/*
给出一个区间的集合，请合并所有重叠的区间。

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
*/

#include <stdlib.h>
#include <stdio.h>

// 其实这个是对的
//int compare(const void *a, const void *b) {
//    return *(int *) b - *(int *) a;
//}

int compare(const void **a, const void **b) {
    return *(int *) a[0] > *(int *) b[0];
}

int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int **), compare);

    int mergeCount = 0;
    int pos = 0;
    for (int i = 1; i < intervalsSize; ++i) {
        if (intervals[pos][1] >= intervals[i][0]) {
            intervals[pos][1] = intervals[pos][1] > intervals[i][1] ? intervals[pos][1] : intervals[i][1];
            mergeCount++;
        } else {
            intervals[++pos][0] = intervals[i][0];
            intervals[pos][1] = intervals[i][1];
        }
    }

    *returnSize = intervalsSize - mergeCount;
    for (int j = 0; j < *returnSize; ++j) {
        // *returnColumnSizes[j] = 2;
        returnColumnSizes[0][j] = 2;
    }
    return intervals;
}

int main() {
    int sub1[2] = {1, 3};
    int sub2[2] = {2, 6};
    int sub3[2] = {8, 10};
    int sub4[2] = {15, 18};
    int *test[4] = {sub1, sub2, sub3, sub4};
    int intervalsColSize[4] = {2, 2, 2, 2};
    int returnSize;
    int c1;
    int c2;
    int c3;
    int c4;
    int *returnColumnSizes[4] = {&c1, &c2, &c3, &c4};
    int **res = merge(test, sizeof(test) / sizeof(int *), intervalsColSize, &returnSize, returnColumnSizes);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d %d\n", res[i][0], res[i][1]);
    }

}

