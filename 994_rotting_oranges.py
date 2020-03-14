"""
在给定的网格中，每个单元格可以有以下三个值之一：
   - 值 0 代表空单元格；
   - 值 1 代表新鲜橘子；
   - 值 2 代表腐烂的橘子。

每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。
返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。

input：[   [2,1,1],
           [1,1,0],
           [0,1,1]    ]
输出：4
"""
class Solution:
    # def orangesRotting(self, grid: List[List[int]]) -> int:
    def orangesRotting(self, grid) -> int:
        R = len(grid)
        C = len(grid[0])

        queue = list()
        rotting_pos = []
        for row, cols in enumerate(grid):
            for col, value in enumerate(cols):
                if value == 2:
                    rotting_pos.append((row, col))
        queue.append(rotting_pos)

        times = 0
        while len(queue) > 0:
            rotting_pos = []
            # rotting_pos.clear()  // 不能使用clear是因为把元素清掉, queue中的也就没有了, 而rotting_pos = []只是重新指向了
            current_li = queue.pop(0)
            for x, y in current_li:
                grid[x][y] = 0
                around = ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1))
                for nr, nc in around:
                    if 0 <= nr < R and 0 <= nc < C and grid[nr][nc] == 1 and ((nr, nc) not in current_li):
                        rotting_pos.append((nr, nc))

            if rotting_pos:
                queue.append(rotting_pos)
                times += 1

        for cols in grid:
            for v in cols:
                if v == 1:
                    return -1
        return times


if __name__ == "__main__":
    li = [[2, 1, 1],
          [1, 1, 0],
          [0, 1, 1]]
    li = [[2, 1, 1], [0, 1, 1], [1, 0, 1]]
    li = [[0, 2]]
    li = [[2, 2],
          [1, 1],
          [0, 0],
          [2, 0]]
    print(Solution().orangesRotting(li))
