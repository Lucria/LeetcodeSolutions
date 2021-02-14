/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // * BFS to get shortest path
        queue<pair<int, int>> q;
        int answer = 0;

        q.push({0, 0});
        while(!q.empty()) {
            answer++;
            queue<pair<int,int>> q2;
            while(!q.empty()) {
                pair<int, int> node = q.front();
                q.pop();
                if (node.first >= 0 && node.second >= 0 && node.first < grid.size() && node.second < grid.size() && !grid[node.first][node.second]) {
                    grid[node.first][node.second] = 1;
                    if (node.first == grid.size() - 1 && node.second == grid.size() - 1) {
                        return answer;
                    }

                    for (int i = -1; i < 2; i++) {
                        for (int j = -1; j < 2; j++) {
                            if (!(i == 0 && j == 0)) {
                                q2.push({node.first + i, node.second + j});
                            }
                        }
                    }
                }
            }
            swap(q, q2);
        }
        return -1;
    }
};
// @lc code=end

