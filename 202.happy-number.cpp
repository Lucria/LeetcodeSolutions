/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    int digitSquare(int n) {
        int sum = 0;
        int digit = 0;
        while (n) {
            digit = n % 10;
            sum += (digit * digit);
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        // Using floyd's tortoise and hare algorithm
        int tortoise = digitSquare(n);
        int hare = digitSquare(digitSquare(n));
        while (tortoise != hare) {
            tortoise = digitSquare(tortoise);
            hare = digitSquare(digitSquare(hare));
        }
        if (tortoise == 1) {
            return 1;
        } else {
            return 0;
        }
    }
};
// @lc code=end

