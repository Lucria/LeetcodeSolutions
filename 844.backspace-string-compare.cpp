/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        // To do it in O(n) time you can just use a stack and append and pop respectively.
        // To do it in O(1) space, you need to compare the string backwards! Starting from the last character and move forward. If we hit a "#", then we know to skip the next charaacter
        int i = S.size() - 1;
        int j = T.size() - 1;


        // The idea is that, read next letter from end to start.
        //If we meet #, we increase the number we need to step back, until back = 0
        while (1) {
            for (int back = 0; i >= 0 && (back || S[i] == '#'); --i)
                back += S[i] == '#' ? 1 : -1;
            for (int back = 0; j >= 0 && (back || T[j] == '#'); --j)
                back += T[j] == '#' ? 1 : -1;
            if (i >= 0 && j >= 0 && S[i] == T[j])
                i--, j--;
            else
                return i == -1 && j == -1;
        }
    }
};
// @lc code=end

