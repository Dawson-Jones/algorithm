#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
*/

int expand(const char *s, int left, int right) {
    while (left >= 0 && s[right] != '\0' && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char *longestPalindrome(char *s) {
    int odd_len, even_len;
    int st = 0;
    int ed = 0;
    int i;

    for (i = 0; s[i] != '\0'; ++i) {
        odd_len = expand(s, i, i);
        even_len = expand(s, i, i + 1);

        if (odd_len > ed - st) {
            st = i - odd_len / 2;
            ed = st + odd_len;
        }

        if (even_len > ed - st) {
            st = i - even_len / 2 + 1;
            ed = st + even_len;
        }
    }

    *(s + ed) = '\0';
    return s + st;
}

int main() {
//    char s[] = "babad";
    char s[] = "sjfodsasdoffdoa";
    printf("res: %s\n", longestPalindrome(s));
    return 0;
}
