import "strings"

/*
 * @lc app=leetcode id=58 lang=golang
 *
 * [58] Length of Last Word
 */

// @lc code=start
func lengthOfLastWord(s string) int {
	allStrings := strings.SplitN(s, " ", -1)
	originalLength := len(s)
	if originalLength == 0 {
		return 0
	}
	length := len(allStrings)
	for i := length - 1; i >= 0; i-- {
		temp := allStrings[i]
		if temp != "" {
			return len(allStrings[i])
		}
	}
	return 0
}

// @lc code=end
