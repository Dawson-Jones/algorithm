package main

import (
	"fmt"
	"math"
)

func maxProfit(prices []int) int {
	hold := prices[0];
	profit := 0
	for _, price := range prices {
		if price - hold > 0 {
			profit = int(math.Max(float64(price-hold), float64(profit)))
		} else {
			hold = price
		}
	}
	return profit
}

func main() {
	prices := []int{7,1,5,3,6,4}
	benefit := maxProfit(prices)
	fmt.Println(benefit)
}