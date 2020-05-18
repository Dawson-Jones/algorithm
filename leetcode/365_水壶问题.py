"""
有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？
如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。

允许：
装满任意一个水壶
清空任意一个水壶
从一个水壶向另外一个水壶倒水，直到装满或者倒空

输入: x = 3, y = 5, z = 4
输出: True

"""
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        stack = [(0,0)]  # 一个元组表示(x,y), 初始状态x, y 水壶都没有水
        seen = set()
        while stack:
            rest_x, rest_y = stack.pop()
            if rest_x == z or rest_y == z or rest_x + rest_y == z:
                return True
            if (rest_x, rest_y) in seen:
                continue
            seen.add((rest_x, rest_y))

            # 状态 6 种
            stack.append((x, rest_y))  # x壶 满
            stack.append((rest_x, y))  # y壶 满
            stack.append((0, rest_y))  # x壶 空
            stack.append((rest_x, 0))  # y壶 空
            # x壶 倒进 y壶, 直到 y满 或 x空
            stack.append((rest_x - min(rest_x, y-rest_y), rest_y+min(rest_x, y-rest_y)))
            # y壶 倒进 x壶, 直到 x满 或 y空
            stack.append((rest_x+min(rest_y, x-rest_x), rest_y-min(rest_y, x-rest_x)))

        return False


if __name__ == "__main__":
    res = Solution().canMeasureWater(3,5,4)
    print(res)