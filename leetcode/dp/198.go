func rob(nums []int) int {
	pre := 0
	cur := 0
	for _, num := range nums {
		if num + pre > cur {
			pre, cur = cur, num + pre
		} else {
			pre = cur
		}
	}

	return cur
}