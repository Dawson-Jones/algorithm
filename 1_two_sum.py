class Solution:
    def twoSum(self, nums, target):
        hash_map = dict()
        for i, num in enumerate(nums):
            if hash_map.get(target - num) is not None:
                return [hash_map.get(target - num), i]
            hash_map[num] = i  # 这句不能放在if语句之前，解决list中有重复值或target-num=num的情况
        print(hash_map)


if __name__ == '__main__':
    nums = [1, 3, 3]
    target = 4
    print(Solution().twoSum(nums, target))
