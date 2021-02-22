/*
 * @lc app=leetcode id=991 lang=cpp
 *
 * [991] Broken Calculator
 */

// @lc code=start
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int answer = 0;
        while (Y > X) {
            Y = Y % 2 ? Y + 1 : Y / 2;
            answer++;
        }
        return answer + X - Y;
    }
};

// @lc code=end

