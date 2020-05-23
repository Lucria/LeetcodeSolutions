/*
 * @lc app=leetcode id=1143 lang=golang
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
func longestCommonSubsequence(text1 string, text2 string) int {
	// Dynamic Programming question
	// If character match, then just need to find common subsequence with one character minused
	size1 := len(text1)
	size2 := len(text2)
	matrix := make([][]int, size1+1)
	for i := 0; i < size1+1; i++ {
		matrix[i] = make([]int, size2+1)
	}

	for i := 1; i < size1+1; i++ {
		for j := 1; j < size2+1; j++ {
			if text1[i-1] == text2[j-1] {
				matrix[i][j] = matrix[i-1][j-1] + 1
			} else {
				if matrix[i][j-1] > matrix[i-1][j] {
					matrix[i][j] = matrix[i][j-1]
				} else {
					matrix[i][j] = matrix[i-1][j]
				}
			}
		}
	}

	return matrix[size1][size2]
}

// @lc code=end
