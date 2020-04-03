/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i : nums) {
            result ^= i;
        }
        return result;
    }
};
// @lc code=end

