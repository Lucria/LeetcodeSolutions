/*
 * @lc app=leetcode id=64 lang=golang
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
func minPathSum(grid [][]int) int {
	row := len(grid)
	length := len(grid[0])
	sum := make([]int, row)
	for i := range sum {
		sum[i] = grid[0][0]
	}

	for i := 1; i < row; i++ {
		sum[i] = sum[i-1] + grid[i][0]
	}

	for j := 1; j < length; j++ {
		sum[0] += grid[0][j]
		for i := 1; i < row; i++ {
			sum[i] = min(sum[i-1], sum[i]) + grid[i][j]
		}
	}

	return sum[row-1]
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

// @lc code=end
