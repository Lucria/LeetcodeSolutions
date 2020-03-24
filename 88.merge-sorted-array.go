/*
 * @lc app=leetcode id=88 lang=golang
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
func merge(nums1 []int, m int, nums2 []int, n int) {
	answer := make([]int, 0, m+n+1)

	counter1, counter2 := 0, 0

	for counter1 < m && counter2 < n {
		if nums1[counter1] < nums2[counter2] {
			answer = append(answer, nums1[counter1])
			counter1++
			// fmt.Println("Counter1 ", counter1)
		} else if nums2[counter2] <= nums1[counter1] {
			answer = append(answer, nums2[counter2])
			counter2++
			// fmt.Println("Counter2 ", counter2)
		}
	}

	for counter1 < m {
		answer = append(answer, nums1[counter1])
		counter1++
		// fmt.Println("Counter1", counter1)
	}

	for counter2 < n {
		answer = append(answer, nums2[counter2])
		counter2++
		// fmt.Println("Counter2", counter2)
	}

	copy(nums1, answer)
}

// @lc code=end
