/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for (auto i: s) {
            if (i == '(' || i == '[' || i == '{') {
                st.push(i);
            } else {
                if (st.size() > 0) {
                    char topEle = st.top();
                    if (i == ')' && topEle != '(') {
                        return false;
                    }
                    if (i == ']' && topEle != '[') {
                        return false;
                    }
                    if (i == '}' && topEle != '{') {
                        return false;
                    }
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        if (st.size() != 0) {
            return false;
        }
        return true;
    }
};
// @lc code=end

