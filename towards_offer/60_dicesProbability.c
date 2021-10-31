class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector <double> dp(6, 1 / 6.);
        for (int i = 2; i <= n; ++i) {
            // 2 个骰子共 (6 * 2) - (2 - 1) 种情况「没有 1 这种情况」
            // i 个骰子共 (6 * i) - (i - 1) 种情况， 化简： 5 * i + 1
            vector <double> tmp(5 * i + 1, 0);
            for (int j = 0; j < dp.size(); ++j) {
                for (int k = 0; k < 6; ++k) {
                    // 除以 6 暂时没怎么理解
                    // 应该是因为多投了一枚骰子，所以之前的概率要除以 6
                    tmp[j + k] += dp[j] / 6.;
                }
            }
            dp = tmp;
        }
        return dp;
    }
}