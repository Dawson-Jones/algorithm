#include "utils/utilsLib.h"

/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

输入: "()"
输出: true

输入: "()[]{}"
输出: true

输入: "(]"
输出: false

输入: "([)]"
输出: false
*/

typedef struct {
    char *s;
    size_t len;
} my_str;

bool isValid(char * s){
    size_t s_l = strlen(s);
    if (s_l % 2) return false;

    size_t l = s_l / 2;
    char temp[l + 1];
    my_str st = { temp, 0 };

    while (*s != '\0') {
        if (st.len > l) return false;

        switch (*s) {
            case '(':
                st.s[st.len++] = '(';
                break;
            case '[':
                st.s[st.len++] = '[';
                break;
            case '{':
                st.s[st.len++] = '{';
                break;
            case ')':
                if (st.len <= 0 || st.s[--st.len] != '(') return false;
                break;
            case ']':
                if (st.len <= 0 || st.s[--st.len] != '[') return false;
                break;
            case '}':
                if (st.len <= 0 || st.s[--st.len] != '{') return false;
                break;
            default:
                break;
        }

        s++;
    }

    return !st.len;
}

int main(int argc, char const *argv[]) {
    printf("res: %d\n", isValid("()"));
    return 0;
}
