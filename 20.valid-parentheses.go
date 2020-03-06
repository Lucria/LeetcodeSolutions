import "fmt"

/*
 * @lc app=leetcode id=20 lang=golang
 *
 * [20] Valid Parentheses
 */

// @lc code=start
func isValid(s string) bool {
	stack := make([]string, 0)
	for _, c := range s {
		if c == '(' || c == '[' || c == '{' {
			stack = append(stack, string(c))
		} else {
			if len(stack) > 0 {
				lastElement := stack[(len(stack) - 1)]
				fmt.Println(lastElement)
				if c == ')' && lastElement != "(" {
					return false
				} else if c == ']' && lastElement != "[" {
					return false
				} else if c == '}' && lastElement != "{" {
					return false
				}
				stack = stack[:len(stack)-1]
			} else {
				return false
			}
		}
	}
	if len(stack) != 0 {
		return false
	}
	return true
}

// @lc code=end
