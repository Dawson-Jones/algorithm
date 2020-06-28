/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例:
输入: "aba"
输出: True
*/

#include "utils/utilsLib.h"

bool validPalindrome(char *s) {
    int low = 0, high = strlen(s) - 1;
    while (low < high) {
        char c1 = s[low], c2 = s[high];
        if (c1 == c2) {
            low++;
            high--;
        } else {
            bool flag1 = true, flag2 = true;
            for (int i = low, j = high - 1; i < j; i++, j--) {
                char c3 = s[i], c4 = s[j];
                if (c3 != c4) {
                    flag1 = false;
                    break;
                }
            }
            for (int i = low + 1, j = high; i < j; i++, j--) {
                char c3 = s[i], c4 = s[j];
                if (c3 != c4) {
                    flag2 = false;
                    break;
                }
            }
            return flag1 || flag2;
        }
    }
    return true;
}

int main() {
    char *s = "abcdba";
    printf("res: %d", validPalindrome(s));
}