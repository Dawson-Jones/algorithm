"""
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
"""
class Solution:
    def translateNum(self, num: int) -> int:
        nums_str = str(num)
        
        pre = int(nums_str[0])
        ppre_sum = 1
        pre_sum = 1
        for num_str in nums_str[1:]:
            cur = int(num_str)
            if 10 <= pre * 10 + cur < 26:
                pre_sum, ppre_sum = ppre_sum + pre_sum, pre_sum
            else:
                ppre_sum = pre_sum
            pre = cur
                
        return pre_sum
