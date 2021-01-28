/*
 * @lc app=leetcode id=1680 lang=cpp
 *
 * [1680] Concatenation of Consecutive Binary Numbers
 */

// @lc code=start
class Solution {
public:
    int concatenatedBinary(int n) {
        long answer = 0;
        long mod = 1e9+7;
        for (int i = 1; i <= n; i++) {
            int len = 0;
            for (int j = i; j; j >>= 1) {
                len++;
            }
            answer = ((answer << len) % mod + i) % mod;
        }
        return answer;
    }
};
// @lc code=end

