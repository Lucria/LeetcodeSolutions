import "strconv"

/*
 * @lc app=leetcode id=38 lang=golang
 *
 * [38] Count and Say
 */

// @lc code=start

// TODO understand this shit
func countAndSay(n int) string {
	if n == 1 {
		return "1"
	}
	result := "1"
	for i := 1; i < n; i++ {
		temp := ""
		j := 0
		for j < len(result) {
			count := 1
			currentChar := result[j]

			for j < len(result)-1 && result[j] == result[j+1] {
				count++
				j++
			}
			j++

			temp += strconv.Itoa(count) + string([]byte{currentChar})
		}
		result = temp
	}
	return result
}

// @lc code=end
