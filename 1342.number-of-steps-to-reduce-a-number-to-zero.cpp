/*
 * @lc app=leetcode id=1342 lang=cpp
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

// @lc code=start
class Solution {
public:
    int numberOfSteps (int num) {
        if (num == 0) return 0;
        long result = 0;
        while (num > 1) {
            num % 2 ? num -= 1 : num /= 2;
            result++;
        }
        result++;
        return result;
    }
};
// @lc code=end

