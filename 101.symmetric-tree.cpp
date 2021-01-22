/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        TreeNode* left = root-> left;
        TreeNode* right = root-> right;
        queue<TreeNode*> q;
        q.push(left);
        q.push(right);
        while (!q.empty()) {
            left = q.front();
            q.pop();
            right = q.front();
            q.pop();
            if (left == NULL && right == NULL) {
                continue;
            }
            if (left == NULL || right == NULL) {
                return false;
            }
            if (left->val != right->val) {
                return false;
            }
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};
// @lc code=end

