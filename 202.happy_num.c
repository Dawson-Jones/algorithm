/**
 * 编写一个算法来判断一个数是不是“快乐数”。
 * 
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

输入: 19
输出: true
解释: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

#include<stdio.h>

int getNext(int n){
    int sum = 0;
    while(n){
        sum +=(n%10)*(n%10);
        n /= 10;
    }
    return sum;
}

int isHappy(int n){
    int next1 = getNext(n);
    int next2 = getNext(getNext(n));
    while(next1!=next2){
        next1 = getNext(next1);
        next2 = getNext(getNext(next2));
    }
    return (next1==1)?1:0;
}

int main(){
    int i = 19;
    int res = isHappy(i);
    printf("The res: %d is %d happy num", i, res);
}
