/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;

        unordered_map<char, int> charMap;
        int maxPoint = 0;
        int start = -1;
        for (int i = 0; i < s.length(); i++) {
            if (charMap.count(s[i]) != 0) {
                start = max(start, charMap[s[i]]);
            }
            charMap[s[i]] = i;
            maxPoint = max(maxPoint, i - start);
        }
        return maxPoint;
    }
};
// @lc code=end

