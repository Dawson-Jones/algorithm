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


// 可以进一步省空间, 简单的
int numDecodings(char *s) {
    int pre = 0, i;
    int len = strlen(s);

    int dp[len + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (i = 0; s[i]; ++i) {
        if (s[i] - '0' > 0)
            dp[i + 1] = dp[i];

        if (pre > 0 && (pre * 10 + s[i] - '0') <= 26)
            dp[i + 1] += dp[i - 1];

        pre = s[i] - '0';
    }

    return dp[len];
}


int main(){
    char *str = "2";
    int res = numDecodings(str);
    printf("%d", res);
    return 0;
}
