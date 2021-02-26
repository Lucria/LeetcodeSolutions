/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        while (i < n && sorted[i] == nums[i]) {
            i++;
        }
        while (j > i && sorted[j] == nums[j]) {
            j--;
        }
        return j - i + 1;
    }
};
// @lc code=end

