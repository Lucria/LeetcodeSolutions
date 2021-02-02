/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        // * Recursive
        // vector<int> result;
        // recursive(root, result);
        // return result;

        // * Iterative
        vector<int> result;
        stack<TreeNode*> s;

        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            result.push_back(root->val);

            root = root->right;
        }
        return result;
    }

private:
    void recursive(TreeNode* node, vector<int>& result) {
        if (node) {
            recursive(node->left, result);
            result.push_back(node->val);
            recursive(node->right, result);
        }
    }
};
// @lc code=end

