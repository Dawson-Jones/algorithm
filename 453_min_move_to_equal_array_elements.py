"""
给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数。每次移动可以使 n - 1 个元素增加 1。
"""


class Solution:
    def min_moves(self, nums: list) -> int:
        count = 0
        while len(set(nums)) != 1:
            max_num = max(nums)
            nums.remove(max_num)
            nums = [i + 1 for i in nums]
            nums.append(max_num)
            count += 1
        return count


if __name__ == '__main__':
    li = [1, 2, 3, 3, 4, 5, 23, 54, 65, 767, 43, 65, 656, 32, 55, 66]
    count = Solution().min_moves(li)
    print("步骤: ", count)

"""
[1,2,3] -> [2,3,3] -> [3,3,4] -> [4,4,4]
"""
