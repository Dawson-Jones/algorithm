#include "utils/utilsLib.h"


bool wordBreak(char *s, char **wordDict, int wordDictSize) {
    size_t s_len = strlen(s);
    bool dp[s_len + 1];
    dp[0] = 1;
    for (int i = 1; i <= s_len; ++i) {
        dp[i] = 0;
    }

    bool in(const char *, int from, int to, char **, int size);
    for (int i = 0; i < s_len; ++i) {
        for (int j = i + 1; j < s_len + 1; ++j) {
            if (dp[i] && in(s, i, j, wordDict, wordDictSize)) dp[j] = 1;
        }
    }
    return dp[s_len];
}

bool in(const char *s, int from, int to, char **word_dict, int size) {
    char *cur_word;
    for (int i = 0; i < size; ++i) {
        cur_word = word_dict[i];

        int tmp = 0;
        int j;
        // break 的时候会直接跳出循环, 而在结束判定的时候, 依然会++j
        for (j = from; j < to; ++j) {
            if (s[j] != cur_word[tmp++]) break;
        }
        if (j == to && cur_word[tmp] == '\0') return true;
    }
    return false;
}

int main() {
    char *s = "leetcode";
    char *wd1 = "leet";
    char *wd2 = "code";
    char *wd[] = {wd1, wd2};
    printf("res: %d\n", wordBreak(s, wd, 2));
}