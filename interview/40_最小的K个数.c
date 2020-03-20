/*
输入整数数组 arr ，找出其中最小的 k 个数。

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

* Note: The returned array must be malloced, assume caller calls free().
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    qsort(arr);

}

int main(int argc, char const *argv[]){
    int arr[] = {1,2,3};
    int k = 2;
    int returnSize = 2;
    int res = getLeastNumbers(arr, 3, k, &returnSize);

    return 0;
}
