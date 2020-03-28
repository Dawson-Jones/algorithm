class Solution:
    def __init__(self):
        self.memo = dict()

    def superEggDrop(self, K: int, N: int):
        return self.dp(K, N)

    def dp(self, K, N) -> int:
        # base case
        if K == 1:
            return N
        if N == 0:
            return 0
        # 避免重复计算
        if (K, N) in self.memo:
            return self.memo[(K, N)]

        res = float('INF')
        # 穷举所有可能的选择
        for i in range(1, N + 1):
            res = min(res, max(self.dp(K, N - i), self.dp(K - 1, i - 1)) + 1)

        # 记入备忘录
        self.memo[(K, N)] = res
        return res


if __name__ == "__main__":
    obj = Solution()
    res = obj.superEggDrop(2, 10)
    print(res)
