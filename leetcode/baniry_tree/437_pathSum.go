var preSum map[int]int

func dfs(root *TreeNode, curSum, targetSum int) int {
	if root == nil {
		return 0
	}

	curSum += root.Val
	count := preSum[curSum-targetSum]
	
	if root.Left == nil && root.Right == nil {
		return count
	}

	preSum[curSum]++
	count = count + dfs(root.Left, curSum, targetSum) + dfs(root.Right, curSum, targetSum)
	preSum[curSum]--
	return count
}

func pathSum(root *TreeNode, targetSum int) int {
	preSum = make(map[int]int)
	preSum[0] = 1
	return dfs(root, 0, targetSum)
}