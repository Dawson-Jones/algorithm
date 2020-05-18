/*
 * 给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，
 * 判断二者是否相等，并返回结果。 # 代表退格字符。

输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。

输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。
 */

#include <stdbool.h>
#include <stdio.h>

void compute(char *s){
    int low = 0;
    int fst = 0;
    while (s[fst] != '\0'){
        if(s[fst] == '#'){
            if (low >0) {
                low--;
            }
        } else {
            s[low] = s[fst];
            low++;
        }
        fst++;
    }
    s[low] = '\0';
}

bool backspaceCompare(char * S, char * T){
    compute(S);
    compute(T);
    while (*S == *T && *S != '\0' && *T != '\0'){
        S++;
        T++;
    }
    return *S == *T;
}

int main(){
    char S[] = "ab##c###";
    char T[] = "ad##c#";
    bool res = backspaceCompare(S, T);
    printf("res: %d\n", res);
    return 0;
}