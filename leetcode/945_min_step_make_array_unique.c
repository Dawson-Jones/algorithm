/**
给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1。
返回使 A 中的每个值都是唯一的最少操作次数。

输入：[1,2,2]
输出：1
解释：经过一次 move 操作，数组将变为 [1, 2, 3]。
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;  // small to big sort
    // return *(int *)b - *(int *)a;  // big to small
}

int minIncrementForUnique(int* A, int ASize){
    if(ASize <= 1) return 0;
    qsort(A, ASize, sizeof(int), cmp);
    
    int curMax = -1;  // 当前数组最大值
    int res = 0;
    for (int i = 0;i<ASize;i++){
        if(A[i] <= curMax){
            int ai = curMax+1;  // 当前元素增加到比当前大1
            res += (ai-A[i]);  // 自增次数
            A[i] = ai;
        }
        curMax = curMax>A[i]?curMax:A[i];
        // 看不懂看动图
        // https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/solution/liang-chong-fang-fa-pai-xu-fa-ji-shu-fa-yu-fu-za-d/
    }
    return res;
}

int main(){
    int A[] = {3,2,1,2,1,7};
    int res = minIncrementForUnique(A, 6);
    printf("res: %d\n", res);
    return 0;
}
