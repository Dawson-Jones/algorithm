"""
在一个 N x N 的坐标方格 grid 中，每一个方格的值 grid[i][j] 表示在位置 (i,j) 的平台高度。
现在开始下雨了。当时间为 t 时，此时雨水导致水池中任意位置的水位为 t 。
你可以从一个平台游向四周相邻的任意一个平台，此时水位必须同时淹没这两个平台。
假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。
你从坐标方格的左上平台 (0，0) 出发。最少耗时多久你才能到达坐标方格的右下平台 (N-1, N-1)？

输入: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
输入: 16
解释:
 0->1->2->3->4
24 23 22 21  5
12<13<14<15<16
11 17 18 19 20
10->9->8->7->6

我们必须等到时间为 16，此时才能保证平台 (0, 0) 和 (4, 4) 是连通的
"""


class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        def hasPath(t):
            if grid[0][0]>t:
                return False
            q = []
            seen = [0]*(n**2)
            dirs = [1, 0, -1, 0, 1]
            q.append(0)
            while q:
                x = q[-1] % n
                y = q[-1] // n
                q.pop()
                if x == n - 1 and y == n - 1:
                    return True 
                for i in range(4):
                    tx = x + dirs[i]
                    ty = y + dirs[i+1]
                    if tx < 0 or ty < 0 or tx >=n or ty >= n or grid[tx][ty]>t:
                        continue
                    key = ty*n + tx
                    if seen[key]:
                        continue
                    seen[key] = 1
                    q.append(key)
            return False

        l = 0
        r = n * n 
        while l < r:
            m = l + (r - l) // 2
            if hasPath(m):
                r = m 
            else:
                l = m + 1
        return l
