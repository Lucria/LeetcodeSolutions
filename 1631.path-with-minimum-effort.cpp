/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), columns = heights[0].size();
        int directions[5] = {-1, 0, 1, 0, -1};

        vector<vector<int>> efforts(rows, vector<int>(columns, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.emplace(0, make_pair(0, 0));
        while(!pq.empty()) {
            int effort = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x ==  rows - 1 && y == columns - 1) return effort;
            if (effort >= efforts[x][y]) {
                continue;
            }
            efforts[x][y] = effort;
            for (int i = 0; i <= 3; i++) {
                int newx = x + directions[i];
                int newy = y + directions[i + 1];
                if (newx < 0 || newx >= rows || newy < 0 || newy >= columns) {
                    continue;
                }
                int newEffort = max(effort, abs(heights[x][y] - heights[newx][newy]));
                pq.emplace(newEffort, make_pair(newx, newy));
            }
        }

        return -1;
    }
};
// @lc code=end

