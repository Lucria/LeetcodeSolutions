/*
 * @lc app=leetcode id=28 lang=golang
 *
 * [28] Implement strStr()
 */

// @lc code=start
func strStr(haystack string, needle string) int {
	// i := strings.Index(haystack, needle)
	if haystack == needle {
		return 0
	}
	if len(needle) > len(haystack) {
		return -1
	}

	for i := 0; i < len(haystack)-len(needle)+1; i++ {
		if haystack[i:i+len(needle)] == needle {
			return i
		}
	}

	return -1
}

// @lc code=end
