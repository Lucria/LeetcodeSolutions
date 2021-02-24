/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */

// @lc code=start
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        int curr = 0;
        for (auto i: S) {
            if (i == '(') {
                s.push(curr);
                curr = 0;
            } else {
                curr = max(curr * 2, 1) + s.top();
                s.pop();
            }
            cout << curr << i << endl;
        }
        return curr;
    }
};
// @lc code=end

