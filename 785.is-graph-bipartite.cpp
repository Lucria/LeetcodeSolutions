/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colourArr(n, -1);

        for (int i = 0; i < n; i++) {
            if (colourArr[i] != -1) continue;
            colourArr[0] = 0;
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int neighbour: graph[curr]) {
                    if (colourArr[neighbour] == -1) {
                        colourArr[neighbour] = 1 - colourArr[curr];
                        q.push(neighbour);
                        // cout << colourArr[neighbour] << " " << neighbour << endl;
                    } else if (colourArr[neighbour] == colourArr[curr]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

