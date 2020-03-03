# 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c
# 使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

"""
示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

"""


def three_sum(nums: list):
    res = list()
    for i in nums:
        copy_nums = nums[:]
        pos = copy_nums.index(i)
        copy_nums.pop(pos)
        for k in copy_nums:
            copy2_nums = copy_nums[:]
            x = -i - k
            pos = copy2_nums.index(k)
            copy2_nums.pop(pos)
            if x in copy2_nums:
                sub_res = [i, k, x]
                sub_res.sort()
                res.append(sub_res)
    new_res = list()
    for r in res:
        if r not in new_res:
            new_res.append(r)
    return new_res


if __name__ == '__main__':
    # 时间未通过
    nums = [-5, 0, -2, 3, -2, 1, 1, 3, 0, -5, 3, 3, 0, -1]
    print(three_sum(nums))
