/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
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
