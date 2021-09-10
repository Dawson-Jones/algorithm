func rob(nums []int) int {
    if len(nums) == 1 {
		return nums[0]
	}
	one := my_rob(nums[:len(nums)-1])
	two := my_rob(nums[1:])
	if one > two {
		return one
	}

	return two
}

func my_rob(nums []int) int {
	pre := 0
	cur := 0
	for _, num := range nums {
		if num + pre > cur {
			pre, cur = cur, num + pre
		} else {
			pre = cur
		}
	}
	if pre > cur {
		return pre
	} else {
		return cur
	}
}
