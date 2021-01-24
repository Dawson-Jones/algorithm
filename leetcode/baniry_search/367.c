/*
给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
说明：不要使用任何内置的库函数，如  sqrt。

输入：16
输出：True
示例 2：

输入：14
输出：False
*/

// 已证明
#include "utils/utilsLib.h"

bool isPerfectSquare(int num){
    if (num < 2) return true;

    unsigned long x = num / 2;
    while (x * x > num) {
        x = (x + num / x) / 2;
    }

    return x * x == num;
}