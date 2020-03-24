/*
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/

#include<stdio.h>

int countPrimes(int n){
    if(!n) return 0;
    int isPrim[n];
    // fill true
    for(int i = 0;i<n;i++)
        isPrim[i] = 1;
    
    for(int i=2;i*i<n;i++){
        if(isPrim[i])
            for(int j = i*i;j<n;j+=i)
                isPrim[j] = 0;
    }

    int count = 0;
    for(int i = 2; i<n;i++)
        if(isPrim[i]) count++;
    return count;
}

int main(int argc, char const *argv[]){
    int num;
    printf("input a num you wanna\n");
    scanf("%d", &num);
    int res = countPrimes(num);
    printf("counts: %d\n", res);
    return 0;
}