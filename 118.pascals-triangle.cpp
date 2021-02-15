/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        for (int i = 0; i < numRows; i++) {
            answer.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j < i; j++) {
                answer[i][j] = answer[i - 1][j - 1] + answer[i - 1][j];
            }
        }
        return answer;
    }
};
// @lc code=end

