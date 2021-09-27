int minDistance(char *word1, char *word2) {
    size_t w1_len = strlen(word1);
    size_t w2_len = strlen(word2);
    int dp[w1_len + 1][w2_len + 1];
    for (int i = 0; i <= w1_len; ++i)
        dp[i][0] = i;
    for (int i = 0; i <= w2_len; ++i)
        dp[0][i] = i;

    for (int i = 1; word1[i - 1]; ++i) {
        for (int j = 1; word2[j - 1]; ++j) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i-1][j-1];
            else 
                dp[i][j] = fmin(dp[i][j-1], dp[i-1][j]) + 1;
        }
    }
    return dp[w1_len][w2_len];
}