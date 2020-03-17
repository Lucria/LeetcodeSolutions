import (
	"fmt"
)

/*
 * @lc app=leetcode id=67 lang=golang
 *
 * [67] Add Binary
 */

// @lc code=start
func addBinary(a string, b string) string {
	lena := len(a) - 1
	lenb := len(b) - 1

	var result string
	var sum byte

	for lena >= 0 || lenb >= 0 || sum == 1 {
		if lena >= 0 {
			sum += a[lena] - '0'
			fmt.Println(a[lena] - '0')
			lena--
		}
		if lenb >= 0 {
			sum += b[lenb] - '0'
			fmt.Println("char in b", b[lenb]-'0')
			lenb--
		}
		fmt.Println("sum is ", sum)

		result = string(sum%2+'0') + result
		sum /= 2
	}
	return result
}

// @lc code=end
