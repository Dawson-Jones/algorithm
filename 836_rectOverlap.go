/*
矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。
如果相交的面积为正，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。
给出两个矩形，判断它们是否重叠并返回结果。

输入：rec1 = [0,0,2,2], rec2 = [1,1,3,3]
输出：true
*/

package main

import (
	"fmt"
	"math"
)

func isRectangleOverlap(rec1 []int, rec2 []int) bool {
	x1 := math.Max(float64(rec1[0]), float64(rec2[0]))
	y1 := math.Max(float64(rec1[1]), float64(rec2[1]))
	x2 := math.Min(float64(rec1[2]), float64(rec2[2]))
	y2 := math.Min(float64(rec1[3]), float64(rec2[3]))
	if x1<x2&&y1<y2{
		return true
	}
	return false
}

func main() {
	rec1 := []int{0, 0, 2, 2}
	rec2 := []int{1, 1, 3, 3}
	//rec1 := []int{0, 0, 1, 1}
	//rec2 := []int{1, 0, 2, 1}
	res := isRectangleOverlap(rec1, rec2)
	fmt.Println(res)

}
