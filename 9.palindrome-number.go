import "fmt"

/*
 * @lc app=leetcode id=9 lang=golang
 *
 * [9] Palindrome Number
 */

// @lc code=start
func isPalindrome(x int) bool {
	new := 0
	old := x
	if x < 0 {
		return false
	}
	for x != 0 {
		remainder := x % 10
		new *= 10
		new += remainder
		x /= 10
	}
	if new == old {
		fmt.Println(new)
		fmt.Println(old)
		return true
	} else {
		return false
	}
}

// @lc code=end
