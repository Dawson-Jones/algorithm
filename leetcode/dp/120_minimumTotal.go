func minimumTotal(triangle [][]int) int {
    if len(triangle) == 1 {
    	return triangle[0][0]
	}

	var res = []int{triangle[0][0]}
	var pre, length int
	for _, arr := range triangle[1:] {
		length = len(res)
		for idx, ele := range arr {
			if idx == 0 {
				pre = ele + res[0]
			} else if idx == length {
				ele = ele + res[idx-1]
				res[idx-1] = pre
				pre = ele
			} else {
				ele = int(math.Min(float64(ele + res[idx-1]), float64(ele + res[idx])))
				res[idx-1] = pre
				pre = ele
			}
		}
		res = append(res, pre)
	}
	pre = math.MaxInt32
	for _, ele := range res {
		if pre > ele {
			pre = ele
		}
	}
	return pre
}