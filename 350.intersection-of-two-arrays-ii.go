/*
 * @lc app=leetcode id=350 lang=golang
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
func intersect(nums1 []int, nums2 []int) []int {
	var smallList, bigList []int
	var answer = []int{}
	if len(nums1) > len(nums2) {
		smallList, bigList = nums2, nums1
	} else {
		smallList, bigList = nums1, nums2
	}

	hashmap := make(map[int]int)
	for _, num := range smallList {
		hashmap[num]++
	}

	for _, num := range bigList {
		_, ok := hashmap[num]
		if ok {
			answer = append(answer, num)
			if hashmap[num] > 1 {
				hashmap[num]--
			} else {
				delete(hashmap, num)
			}
		}
	}

	return answer
}

// @lc code=end
