/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        // BFS to build mapping with coordinates
        while(!q.empty()) {
            auto i = q.front();
            q.pop();
            TreeNode* node = i.first;
            int x = i.second.first;
            int y = i.second.second;
            nodes[x][y].insert(node -> val);
            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> result;
        for (auto i: nodes) {
            vector<int> col;
            for (auto j: i.second) {
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            result.push_back(col);
        }
        return result;
    }
};
// @lc code=end

