/*
给定不同面额的硬币 coins 和一个总金额 amount。
编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
*/

package main

import (
	"fmt"
	"math"
	"sort"
)

// 贪心加递归可能会好一些
func coinChange(coins []int, amount int) int {
	var dp []int
	dp = append(dp, 0)
	for i := 1; i <= amount; i++ {
		pieces := 1 << 30
		for _, v := range coins {
			if i-v >= 0 {
				pieces = int(math.Min(float64(pieces), float64(dp[i-v])+1))
			}
		}
		dp = append(dp, pieces)
	}
	return dp[amount]
}

func greedy(coins []int, amount int) int {
	sort.Ints(coins)
	length := len(coins)
	maxNum := coins[length-1]
	coins = coins[:length-1]
	count := amount / maxNum
	remainder := amount % maxNum

	// 对余数进行dp  // 如果是用贪心, 这里不应该用动态规划应该使用记忆化递归应该会更好
	var res int
	for {
		temp := coinChange(coins, remainder)
		if temp < 1<<30 {
			res = temp + count
			break
		}
		if count > 0 {
			count--
			remainder += maxNum
		} else {
			return -1
		}
	}
	return res
}

func main() {
	// 哈哈哈, 事实证明贪心加dp, 不行
	typeCoin := []int{186,419,83,408}
	res := greedy(typeCoin, 6249)
	// 这个结果的最优是20, 贪心加dp的结果是26
	fmt.Println(res)
}
