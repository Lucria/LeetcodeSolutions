/*
 * @lc app=leetcode id=678 lang=golang
 *
 * [678] Valid Parenthesis String
 */

// @lc code=start
func checkValidString(s string) bool {
	min := 0
	max := 0
	for _, c := range s {
		if c == '(' {
			min += 1
			max += 1
		}
		if c == ')' {
			if min-1 > 0 {
				min -= 1
			} else {
				min = 0
			}
			max -= 1
		}
		if c == '*' {
			max += 1
			if min-1 > 0 {
				min -= 1
			} else {
				min = 0
			}
		}
		if max < 0 {
			return false
		}
	}
	return (min == 0)
}

// @lc code=end
