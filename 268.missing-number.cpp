/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        int presentSum = 0;
        for (int i = 1; i < n + 1; i++) {
            presentSum += nums[i - 1];
            totalSum += i;
        }
        return totalSum - presentSum;
    }
};
// @lc code=end

