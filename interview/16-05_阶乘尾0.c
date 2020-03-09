/**
 * 设计一个算法，算出 n 阶乘有多少个尾随零。
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int trailingZeroes(int n){
    int res = 0;
    for(;n>=5;n/=5)
        res += n/5;
    return res;
}

int main(int argc, char const *argv[]){
    int res = trailingZeroes(93);
    printf("%d\n", res);
    return 0;
}
