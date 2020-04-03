/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        int sums = nums[0];
        int currentMax = nums[0];

        for (int i = 1; i < length; i++) {
            if (sums < 0) {
                sums = nums[i];
            } else {
                sums += nums[i];
            }

            if (currentMax < sums) {
                currentMax = sums;
            }
        }

        return currentMax;
    }
};
// @lc code=end


