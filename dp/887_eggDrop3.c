// K 个鸡蛋, N 层楼, 找出找到边界层的最少步骤 F

#include <stdio.h>

int superEggDrop(int K, int N) {
    if (K == 1){
        return N;
    }
    if (N == 1){
        return 1;
    }
    int F = N;
    int dp[K][F];
    for (int i = 0; i < K; ++i) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < F; ++j) {
        dp[0][j] = j + 1;
    }

    for (int f = 1; f < F; ++f) {
        for (int k = 1; k < K; ++k) {
            dp[k][f] = dp[k - 1][f - 1] + dp[k][f - 1] + 1;
            if (dp[k][f] >= N)
                return f + 1;
        }
    }
    return 0;
}

int main() {
    int res = superEggDrop(2, 100);
    printf("res: %d", res);
    return 0;
}