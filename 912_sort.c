/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// qsort from the C programming language
// but it did't pass the exam on leetcode
// it's correct though
#include <stdio.h>
#include<stddef.h>
#include<stdlib.h>

void my_swap(int *v, int i, int j){
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void my_qsort(int v[], int left, int right){
    int i, last;
    if (left>=right)
        return;
    last = left;
    for(i = left+1;i<=right;i++)
        if(v[i]<v[left])
            my_swap(v, ++last, i);

    my_swap(v, left, last);
    my_qsort(v, left, last-1);
    my_qsort(v, last+1, right);
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    my_qsort(nums, 0, numsSize-1);
    return nums;
}

int main(int argc, char const *argv[])
{
    int arr[] = {4,6,3,8,5,2,7,4};
    int size = sizeof(arr) / sizeof(arr[0]);
    sortArray(arr, size, &size);
    for(int i=0;i<size;i++)
        printf("%d\n", arr[i]);
    return 0;
}
