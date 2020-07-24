#include "utils/utilsLib.h"

int coinChange(int* coins, int coinsSize, int amount){
    int dp[amount + 1];
    int max = amount + 1;
    dp[0] = 0;
    for (int k = 1; k <= amount; ++k) {
        dp[k] = max;
    }

    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < coinsSize; ++j) {
            if (coins[j] <= i) {
                dp[i] = dp[i-coins[j]]+1 < dp[i] ? dp[i-coins[j]]+1 : dp[i];
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    int coins[] = {1, 2, 5};
    printf("res: %d\n", coinChange(coins, 3, 11));
}