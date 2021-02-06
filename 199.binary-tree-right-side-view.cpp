/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preorder(root, 1, ans);
        return ans;
    }

private:
    void preorder(TreeNode* root, int depth, vector<int>& ans) {
        if (!root) return;
        if (ans.size() < depth) {
            ans.push_back(root->val);
        }
        preorder(root->right, depth + 1, ans);
        preorder(root->left, depth + 1, ans);
    }
};
// @lc code=end

