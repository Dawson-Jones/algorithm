/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/

#include<stdio.h>

int
trap(const int *height, int heightSize) {
    if (heightSize < 3) return 0;
    int res = 0;
    int stack[heightSize];
    stack[0] = 0;
    int cur = 0;
    for (int i = 1; i < heightSize; ++i) {
        while (cur >= 0 && height[stack[cur]] <= height[i]) {
            int tempHeight = height[stack[cur--]];
            if (cur < 0) break;
            int h = height[stack[cur]] > height[i] ? height[i] : height[stack[cur]];  // 计算出两边比较小的高度
            h -= tempHeight;  // 盛水的高度
            res += h * (i - stack[cur] - 1);
        }
        stack[++cur] = i;
    }
    return res;
}

int
main(int argc, char const *argv[]) {
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//    int arr[] = {5, 5, 1, 7, 1, 1, 5, 2, 7, 6};
    int res = trap(arr, sizeof(arr) / sizeof(int));
    printf("res: %d\n", res);
    return 0;
}
