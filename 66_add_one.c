/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>


int reverse(int *point, int size){
    int res = 0;
    for (int i =1;i<=size;i++)
        res += (point[size-i]*(i));
    return res;
}

int *plusOne(int *digits, int digitsSize, int *returnSize){
    int mid_res = reverse(digits, digitsSize);
    int i = 1;
    int res[5000];
    while (res%i!=0){
        /* code */
    }
}

int main(int argc, char const *argv[]){
    int arr[] = {1, 2, 3, 4, 5};
    int *res = plusOne(arr, 5, 0);
    for (int i =0;i<7;i++)
        printf("%d\n", res[i]);
    return 0;
}
