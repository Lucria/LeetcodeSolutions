/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int p1 = 0;
        int p2 = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[p1] > 1) {
                p1 = p2;
            }
            if (nums[i] != nums[i - 1]) {
                p2 = i;
            }
            if (nums[i] - nums[p1] == 1) {
                result = max(result, i - p1 + 1);
            }
        }
        return result;
    }
};
// @lc code=end

