/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        generate("", results, 0, 0, n);
        return results;
    }

private:
    void generate(string s, vector<string>& results, int open, int close, int max) {
        if (s.length() == max * 2) {
            results.push_back(s);
            return;
        }

        if (open < max) {
            generate(s + "(", results, open + 1, close, max);
        }
        if (close < open) {
            generate(s + ")", results, open, close + 1, max);
        }
    }
};
// @lc code=end

