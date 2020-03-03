# 给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10n次方 。


class Solution:

    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n>10:
            return 0
        dp = list()
        dp.append(1)
        dp.append(10)
        for i in range(2, n + 1):
            temp = 9
            for j in range(i-1):
                temp *= (9 - j)
            temp += dp[i-1]
            dp.append(temp)
        return dp[n]


Solution().countNumbersWithUniqueDigits(9)
