import "sort"

/*
 * @lc app=leetcode id=1046 lang=golang
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
func lastStoneWeight(stones []int) int {
	sort.Ints(stones)
	for len(stones) > 1 {
		length := len(stones)
		smashed := stones[length-1] - stones[length-2]
		if smashed == 0 {
			stones = stones[:length-2]
		} else {
			stones = append(stones[:length-2], smashed)
		}
		sort.Ints(stones)
	}
	if len(stones) == 0 {
		return 0
	}
	return stones[0]
}

// @lc code=end
