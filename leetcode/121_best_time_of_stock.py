class Solution:
    def maxProfit(self, prices: list) -> int:
        if not prices:
            return 0
        counts = len(prices)
        benefits = list()
        benefits.append(0)
        cur_min = prices[0]
        for i in range(1, counts):
            cur_min = min(prices[i], cur_min)
            benefit = prices[i] - cur_min
            benefits.append(max(benefit, benefits[i-1]))
        return benefits[counts-1]


if __name__ == '__main__':
    arr = [7, 2, 5, 3, 1, 3]
    print(Solution().maxProfit(arr))
