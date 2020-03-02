/*
 * @lc app=leetcode id=1 lang=golang
 *
 * [1] Two Sum
 */

// @lc code=start
func twoSum(nums []int, target int) []int {
	indexes := make(map[int]int)
	for i, value := range nums {
		j, found := indexes[target-value]
		if found {
			myAns := []int{j, i}
			return myAns
		}
		indexes[value] = i
	}

	myAns := []int{-1, -1}
	return myAns
}

// @lc code=end
