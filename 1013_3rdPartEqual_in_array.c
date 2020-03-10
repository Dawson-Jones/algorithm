#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<math.h>
/**
 * 给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。
 */

/*
超时, 这个算法是, 
1. dp累加所有的, 找任意第一个值, 
2. 遍历 第二个值等于第一个值的时候, 
3. 直接看第三个值是不是跟前面相等
    1) 相等, 返回True
    2) 不等, 重新找第一个值
bool canThreePartsEqualSum(int* A, int ASize){
    int dp[ASize];
    dp[0] = A[0];
    for(int i=1;i<ASize;i++)
        dp[i] = dp[i-1] + A[i];
    
    int part2=0;
    for(int c1=0;c1<ASize-2;c1++){
        for(int c2=c1+1;c2<ASize-1;c2++){
            part2 = dp[c2]-dp[c1];
            if(part2!=dp[c1]) continue;

            if(dp[ASize-1]-dp[c2]==part2)
                return 1;
            else
                break;
        }
    }
    return 0;
}
*/
bool canThreePartsEqualSum(int* A, int ASize){
    // sum/3 得到指定值, 遍历找到指定值作为part1, 遍历剩下的部分, 找到part2, 返回True, 否则False
    int sum(int *array, int size);
    int sum_res = sum(A, ASize);
    if (sum_res%3!=0) return false;
    int aver = sum_res/3;
    int cut1=0, cut2;
    int res = 0;
    for(cut1;cut1<ASize-2;cut1++){  // 最少保留两个
        res += A[cut1];
        if (res==aver) break;
    }
    if (res!=aver) return false;
    for(cut2=cut1+1;cut2<ASize-1;cut2++){  // 最少保留一个
        res += A[cut2];
        if(res==aver*2) return true;
    }
    return false;
}

int sum(int *array, int size){
    int res = 0;
    for(;size>0;size--)
        res += *array++;  // 从右向左 先++ 在*
    return res;
}


int main(int argc, char const *argv[]){
    int li[] = {0,2,1,-6,6,-7,9,1,2,0,1};
    int len = sizeof(li)/sizeof(int);
    int res = canThreePartsEqualSum(li, len);
    printf("length: %d, res: %d\n", len, res);
    return 0;
}
