/*
给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

输入: "abcabcabcabc"
输出: True
解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
*/

#include "utils/utilsLib.h"

bool is_substr(char *ori_str, char *sub_str, size_t sub_len) {
    ori_str += sub_len;

    int count = 0;
    while (*ori_str != '\0') {
        if (*ori_str++ == sub_str[count++]) {
            if (count == sub_len)
                count = 0;
        } else {
            return false;
        }
    }

    return count ? false : true;
}

bool repeatedSubstringPattern(char *s) {
    size_t length = strlen(s);
    char substr[length + 1];
    memset(substr, 0, length + 1);
    size_t substr_len = 0;

    for (int i = 0; i < length; ++i) {
        if (s[i] != substr[0])
            substr[substr_len++] = s[i];
        else {
            if (length % substr_len != 0 || !is_substr(s, substr, substr_len))
                substr[substr_len++] = s[i];
            else return true;
        }
    }

    return false;
}

int main() {
    printf("res: %d\n", repeatedSubstringPattern("abaababaab"));
}