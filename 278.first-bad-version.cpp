/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long lower = 1, upper = n;
        long mid;
        while (lower < upper) {
            mid = (lower + upper) / 2;
            if (!isBadVersion(mid)) {
                lower = mid + 1;
            } else {
                upper = mid;
            }
        }
        return int(lower);
    }
};
// @lc code=end

