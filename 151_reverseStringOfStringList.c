/*
 * 给定一个字符串，逐个翻转字符串中的每个单词。

输入: "the sky is blue"
输出: "blue is sky the"
 */

#include <stdio.h>
#include <string.h>

void rev(char *s, int i, int j) {
    while (i < j) {
        char temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
}

char *reverseWords(char *s) {
    int pos = 0, flag = 0;
    unsigned int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (s[i] != ' ' && !flag) {
            pos = i;
            flag = 1;
        }
        if (s[i] == ' ' && flag) {
            rev(s, pos, i - 1);
            pos = i;
            flag = 0;
        }
    }
    if (pos != len - 1)
        rev(s, pos, len - 1);
    rev(s, 0, len - 1);

    pos = 0, flag = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == ' ') {
            if (flag) {
                s[pos++] = s[i];
                flag = 0;
            }
        } else {
            s[pos++] = s[i];
            flag = 1;
        }
    }
    if (pos > 1 && s[pos - 1] == ' ')
        pos--;
    s[pos] = '\0';
    return s;
}

int main() {
    char s[] = "the sky is blue";
    char *res = reverseWords(s);
    printf("%s\n", res);

    return 0;
}