import "fmt"

/*
 * @lc app=leetcode id=13 lang=golang
 *
 * [13] Roman to Integer
 */

// @lc code=start
func romanToInt(s string) int {
	var answer int = 0
	var greatest int = 0
	c := map[rune]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}

	for i := len(s) - 1; i >= 0; i-- {
		letter := s[i]
		number := c[rune(letter)]
		if number >= greatest {
			greatest = number
			fmt.Println(greatest)
			answer += number
			continue
		}

		answer = answer - number
	}
	return answer
}

// @lc code=end
