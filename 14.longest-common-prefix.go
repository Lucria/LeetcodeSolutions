import "fmt"

/*
 * @lc app=leetcode id=14 lang=golang
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
func longestCommonPrefix(strs []string) string {
	var small string
	smallestLength := 999
	for _, word := range strs {
		if len(word) < smallestLength {
			small = word
			smallestLength = len(word)
		}
	}

	fmt.Println(small)
	fmt.Println(smallestLength)

	for _, word := range strs {
		for j := 0; j < smallestLength; j++ {
			if word[j] != small[j] {
				fmt.Println(string(word[j]))
				fmt.Println(string(small[j]))
				smallestLength = j
				fmt.Println("Smallest Lenght is ", smallestLength)
				small = small[:smallestLength]
				fmt.Println(small)

			}
		}
	}

	return small
}

// @lc code=end
