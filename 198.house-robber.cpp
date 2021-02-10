/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int prev = 0;
        int prev2 = 0;
        for (auto i : nums) {
            int temp = prev;
            prev = max(prev, prev2 + i);
            prev2 = temp;
        }
        return prev;
    }
};
// @lc code=end

