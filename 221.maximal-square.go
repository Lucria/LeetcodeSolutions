import (
	"strconv"
)

/*
 * @lc app=leetcode id=221 lang=golang
 *
 * [221] Maximal Square
 */

// @lc code=start
func maximalSquare(matrix [][]byte) int {
	if len(matrix) == 0 {
		return 0
	}

	height := len(matrix)
	width := len(matrix[0])
	answer := 0
	dp := make([][]int, height) // Make automatically makes a zeroed array
	for i := range dp {
		dp[i] = make([]int, width)
	}

	for i := 0; i < height; i++ {
		for j := 0; j < width; j++ {
			if i == 0 || j == 0 || matrix[i][j] == '0' {
				placeholder, _ := strconv.Atoi((string(matrix[i][j])))
				dp[i][j] = placeholder
			} else if matrix[i][j] == '1' {
				dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1
			}
			answer = max(dp[i][j], answer)
		}
	}

	return answer * answer
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

// @lc code=end
