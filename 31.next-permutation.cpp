/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
        int len = nums.size();
        int largest = -1;
        int nextLargest = 0;
        // Find the largest index where the next number is bigger
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                largest = i;
            }
        }
        // If array is already in ascending order
        if (largest == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the largest index that is bigger than nums[largest]
        for (int j = len - 1; j > largest; j--) {
            if (nums[j] > nums[largest]) {
                nextLargest = j;
                break;
            }
        }
        // Swap and reverse subarray behind
        swap(nums[largest], nums[nextLargest]);
        reverse(nums.begin() + largest + 1, nums.end());
    }
};
// @lc code=end

