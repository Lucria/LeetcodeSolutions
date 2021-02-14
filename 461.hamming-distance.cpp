/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x ^ y;
        int ans = 0;
        while (res > 0) {
            ans += res & 1;
            res >>= 1;
        }
        return ans;
    }
};
// @lc code=end

