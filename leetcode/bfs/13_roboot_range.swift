/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1]。
从坐标 [0, 0] 的格子开始移动，可以向左、右、上、下移动
不能移动到方格外,
也不能进入行坐标和列坐标的数位之和大于k的格子
例如，当k为18时，能够进入方格 [35, 37] ，因为3+5+3+7=18。
但不能进入方格 [35, 38]，因为3+5+3+8=19

输入：m = 2, n = 3, k = 1
输出：3
 */
 
class Solution {
    func movingCount(_ m: Int, _ n: Int, _ k: Int) -> Int {
        var res = 1;
        var seen: Set<[Int]> = [[0,0]]
        var bfs = [[0, 0]]
        while !(bfs.isEmpty) {
            let ele = bfs.remove(at: 0)
            let top = ele[0] - 1
            let btm = ele[0] + 1
            let lft = ele[1] - 1
            let rgt = ele[1] + 1
            if top >= 0 && !seen.contains([top, ele[1]]) && (self.everyPlaceSum(top) + self.everyPlaceSum(ele[1])) <= k {
                bfs.append([top, ele[1]])
                seen.insert([top, ele[1]])
                res += 1
            }
            if btm < m  && !seen.contains([btm, ele[1]])  && (self.everyPlaceSum(btm) + self.everyPlaceSum(ele[1])) <= k {
                bfs.append([btm, ele[1]])
                seen.insert([btm, ele[1]])
                res += 1
            }
            if lft >= 0 && !seen.contains([ele[0], lft])  && (self.everyPlaceSum(lft) + self.everyPlaceSum(ele[0])) <= k {
                bfs.append([ele[0], lft])
                seen.insert([ele[0], lft])
                res += 1
            }
            if rgt < n  && !seen.contains([ele[0], rgt])  && (self.everyPlaceSum(rgt) + self.everyPlaceSum(ele[0])) <= k {
                bfs.append([ele[0], rgt])
                seen.insert([ele[0], rgt])
                res += 1
            }
        }
        return res
    }
    
    func everyPlaceSum(_ x: Int) -> Int {
        if x == 0 {
            return 0
        }
        return x % 10 + self.everyPlaceSum(x / 10)
    }
}

int res = Solution().movingCount(2,3,1)
print("res: \(res)")
