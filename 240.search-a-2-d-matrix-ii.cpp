/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int temp = 0;
        int temp2 = n - 1;
        while (temp < m && temp2 >= 0) {
            if (matrix[temp][temp2] == target) {
                return true;
            }
            matrix[temp][temp2] > target ? temp2-- : temp++;
        }
        return false;
    }
};
// @lc code=end

