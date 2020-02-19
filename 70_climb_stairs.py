# 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

"""
可以理解为: 每加一阶, 是前1阶迈一个台阶, 或者前2阶迈两个台阶
"""


class Solution:
    def climbStairs(self, n: int) -> int:
        sol = list()
        sol.append(1)
        sol.append(2)
        if n < 3:
            return sol[n-1]
        for i in range(2, n):
            sol.append(sol[i - 1] + sol[i - 2])
        return sol[n-1]


if __name__ == '__main__':
    print(Solution().climbStairs(4))
