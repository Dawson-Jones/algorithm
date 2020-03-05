"""
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

示例:
    输入：target = 9
    输出：[[2,3,4],[4,5]]
"""

class Solution:
    # def findContinuousSequence(self, target: int) -> List[List[int]]:
    def findContinuousSequence(self, target: int) -> list:
        li = list()
        n = 2
        while True:
            mid = target//n
            remainder = target % n
            if n % 2==0:
                if remainder != n//2:
                    n += 1
                    continue
                st = mid-remainder+1
                if st>0:
                    li.append(list(range(st, st+n)))
                    n+=1
                else:
                    break
            else:
                if remainder != 0:
                    n+=1
                    continue
                st = mid - (n-1)//2
                if st>0:
                    li.append(list(range(st, st+n)))
                    n+=1
                else:
                    break
        # li.sort()
        li.reverse()
        return li

if __name__ == "__main__":
    res = Solution().findContinuousSequence(9)
    print(res)


