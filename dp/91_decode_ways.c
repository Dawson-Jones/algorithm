/*
一条包含字母 A-Z 的消息通过以下方式进行了编码：
'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
示例 2:

输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
*/


#include <stdio.h>
int conver(char c){
    return c - '0';
}

int len(char *s){
    int n = 0;
    while (*s != '\0'){
        n++;
        s++;
    }
    return n;
}
int numDecodings(char *s){
    int n = len(s);
    if (n == 0) return 0;
    if (n == 1&&s[0]!='0') return 1;
    if (s[0] == '0') return 0;

    int dp[1000];
    dp[0] = 1;
    int i;

    if (s[1] == '0'){
        if (conver(s[0]) * 10 + conver(s[1]) <= 26)
            dp[1] = 1;
        else
            return 0;
    }
    else{
        if (conver(s[0]) * 10 + conver(s[1]) <= 26)
            dp[1] = 2;
        else
            dp[1] = 1;
    }
    if (n==2)
        return dp[1];

    for (i = 2; s[i] != '\0'; i++){
        if (s[i - 1] == '0'){
            if (s[i] == '0')
                return 0;
            else
                dp[i] = dp[i - 1];
        }
        // 前一位不等于0
        else{
            if (s[i] == '0'){
                if (conver(s[i - 1]) * 10 + conver(s[i]) <= 26)
                    dp[i] = dp[i - 2]; // 后两位结合
                else
                    return 0;
            }
            // 后一位也不是0
            else{
                if (conver(s[i - 1]) * 10 + conver(s[i]) <= 26)
                    dp[i] = dp[i - 1] + dp[i - 2]; // dp[i-1]: dp[i]自己组合, dp[i-2]: dp[i-1]和dp[i] 组合
                else // 只能自己, 不能组合
                    dp[i] = dp[i - 1];
            }
        }
    }
    return dp[i - 1];
}

int main(){
    char *str = "2";
    int res = numDecodings(str);
    printf("%d", res);
    return 0;
}
