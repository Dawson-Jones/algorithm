/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

输入: ["flower","flow","flight"]
输出: "fl"
*/
#include "utils/utilsLib.h"

char *longestCommonPrefix(char **strs, int strsSize) {
    char *prefix = (char *) malloc(1000);
    int idx = 0;
    if (!strsSize) {
        prefix[idx] = '\0';
        return prefix;
    }
    int flag = 1;
    while (flag) {
        char cur_char = **strs;
        for (int i = 0; i < strsSize; ++i) {
            if (*strs[i] == '\0') {
                flag = 0;
                break;
            }
            if (*strs[i]++ != cur_char) {
                flag = 0;
                break;
            }
        }
        if (flag) prefix[idx++] = cur_char;
    }
    prefix[idx] = '\0';
    return prefix;
}
