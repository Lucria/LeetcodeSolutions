/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack == needle) return 0;
        if (needle.size() > haystack.size()) return -1;

        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i < n - m + 1; i++) {
            if (haystack.substr(i, m) == needle) return i;
        }

        return -1;
    }
};
// @lc code=end

