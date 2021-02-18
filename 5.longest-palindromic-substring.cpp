/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;

        int n = s.size();
        bool table[n][n];
        memset(table, 0, sizeof(table));

        int maxLength = 1;
        for (int i = 0; i < n; i++) {
            table[i][i] = true;
        }

        int start = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                table[i][i+1] = true;
                start = i;
                maxLength = 2;
            }
        }

        for (int i = 3; i <= n; i++) {
            for (int startingIndex = 0; startingIndex < n - i + 1; startingIndex++) {
                int endingIndex = i + startingIndex - 1;
                if (table[startingIndex + 1][endingIndex - 1] && s[startingIndex] == s[endingIndex]) {
                    table[startingIndex][endingIndex] = true;

                    if (i > maxLength) {
                        start = startingIndex;
                        maxLength = i;
                    }
                }
            }
        }

        string result = s.substr(start, maxLength);
        return result;
    }
};
// @lc code=end

