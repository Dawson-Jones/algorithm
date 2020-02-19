"""
不相邻数组的sum最大值
"""


class Solution:
    def rob(self, nums: list) -> int:
        opt = list()
        opt.append(nums[0])
        opt.append(max(nums[0], nums[1]))
        for i in range(2, len(nums)):
            a = opt[i - 2] + nums[i]
            b = opt[i - 1]
            opt.append(max(a, b))
        return opt[len(nums) - 1]


if __name__ == '__main__':
    arr = [1, 2, 4, 1, 7, 8, 3]
    print(Solution().rob(arr))
