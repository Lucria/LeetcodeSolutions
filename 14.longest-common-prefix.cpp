/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string smallestString = "";
        int smallestLength = INT_MAX;
        for (auto it: strs) {
            if (it.length() < smallestLength) {
                smallestString = it;
                smallestLength = it.length();
            }
        }

        for (auto it: strs) {
            for (int i = 0; i < smallestLength; i++) {
                if (it[i] != smallestString[i]) {
                    smallestLength = i;
                    smallestString = smallestString.substr(0, i);
                }
            }
        }

        return smallestString;
    }
};
// @lc code=end

