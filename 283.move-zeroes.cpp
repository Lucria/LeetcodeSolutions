/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto it = nums.begin();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                *it = nums[i];
                it++;
            }
        }
        while (it != nums.end()) {
            *it = 0;
            it++;
        }
    }
};
// @lc code=end

