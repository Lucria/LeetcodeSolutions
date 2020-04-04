/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    long reverse(int x) {
        long result = 0;
        while (x != 0) {
            int remainder = x % 10;
            result *= 10;
            result += remainder;
            x /= 10;
        }

        if (result > INT_MAX || result < INT_MIN) {
            return 0;
        }
        return result;
    }
};
// @lc code=end

