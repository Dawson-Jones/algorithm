var res int

func findMax(args ...int) int {
	res := args[0]

	for _, arg := range args{
		if arg > res {
			res = arg
		}
	}
	
	return res
}

func helper(root *TreeNode) int {
	if root == nil {
		return 0
	}
	l := helper(root.Left)
	r := helper(root.Right)
	res = findMax(l + root.Val, r + root.Val, r + l + root.Val, root.Val, res)
	return findMax(l + root.Val, r + root.Val, root.Val)
}

func maxPathSum(root *TreeNode) int {
    res = math.MinInt32
	helper(root)
	return res
}