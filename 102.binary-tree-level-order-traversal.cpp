/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        queue<TreeNode*> s;
        queue<TreeNode*> nextLevel;
        s.push(root);
        vector<int> currentLevel;
        while (!s.empty()) {
            TreeNode* i = s.front();
            s.pop();
            currentLevel.push_back(i->val);
            if (i->left) {
                nextLevel.push(i->left);
            }
            if (i->right) {
                nextLevel.push(i->right);
            }
            if (s.empty()) {
                result.push_back(currentLevel);
                currentLevel.clear();
                swap(s, nextLevel);
            }
        }
        return result;
    }
};
// @lc code=end

