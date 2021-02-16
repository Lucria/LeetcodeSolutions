/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        set<pair<int, int>> map;
        for (int i = 0; i < mat.size(); i++) {
            int sum = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                sum += mat[i][j];
            }
            map.insert({sum, i});
        }
        for (auto it: map) {
            if (k <= 0) break;
            result.push_back(it.second);
            k--;
        }
        return result;
    }
};
// @lc code=end

