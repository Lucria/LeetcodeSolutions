/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

    int height(TreeNode* node, int& diameter) {
        if (node == nullptr) {
            return 0;
        }
        int left_height = height(node->left, diameter);
        int right_height = height(node->right, diameter);

        int max_diameter = left_height + right_height;
        diameter = max_diameter > diameter ? max_diameter : diameter;
        int max_height = left_height > right_height ? left_height : right_height;
        return max_height + 1;
    }
};
// @lc code=end

