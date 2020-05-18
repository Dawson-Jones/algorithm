"""
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。
"""
class Solution:
    # def majorityElement(self, nums: List[int]) -> int:
    def majorityElement(self, nums: list) -> int:
        res = dict()
        count = len(nums)
        for e in nums:
            if res.get(e):
                res[e] +=1
            else:
                res[e] = 1

            if res[e] > count/2:
                return e


if __name__ == "__main__":
    li = [2,2,1,1,1,2,2]
    res = Solution().majorityElement(li)
    print(res)