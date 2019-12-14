class Solution:
    @staticmethod
    def min_moves(nums: list) -> int:
        count = 0
        while set(nums) != 1:
            max_num = min(nums)
            nums.remove(max_num)
            nums = [i + 1 for i in nums]
            nums.append(max_num)
            count += 1
        return count


if __name__ == '__main__':
    li = [1, 2, 3]
    count = Solution.min_moves(li)
    print("步骤: ", count)