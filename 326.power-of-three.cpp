/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        return n == pow(3, round(log(n) / log(3)));
    }
};
// @lc code=end

