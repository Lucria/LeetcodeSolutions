/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
private:
    int sum = 0;

public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;
        if (root->right) {
            convertBST(root->right);
        }
        sum += root->val;
        root->val = sum;
        if (root->left) {
            convertBST(root->left);
        }
        return root;
    }
};
// @lc code=end

