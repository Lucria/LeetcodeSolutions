/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int small = 0;
        int big = nums.size() - 1;

        while (small < big) {
            int mid = (small + big) / 2;
            int beside = mid + 1;
            if (nums[mid] < nums[beside]) {
                small = beside;
            } else {
                big = mid;
            }
        }
        return small;
    }
};
// @lc code=end

