/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowChecks[9][9] = {};
        int colChecks[9][9] = {};
        int blocks[3][3][9] = {};
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.') {
                    int temp = board[row][col] - '1';
                    if (rowChecks[row][temp]) {
                        return 0;
                    }
                    if (colChecks[col][temp]) {
                        return 0;
                    }
                    if (blocks[row/3][col/3][temp]) {
                        return 0;
                    }
                    rowChecks[row][temp]++;
                    colChecks[col][temp]++;
                    blocks[row/3][col/3][temp]++;
                }
            }
        }
        return 1;
    }
};
// @lc code=end

