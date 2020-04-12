/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        int maxD = 0;
        if (root == nullptr) {
            return 0;
        }
        int leftMax = findDepth(root->left);
        int rightMax = findDepth(root->right);
        maxD = (leftMax > rightMax) ? leftMax + 1 : rightMax + 1;
        return maxD;
    }

    int findDepth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftDepth = findDepth(node->left);
        int rightDepth = findDepth(node->right);
        return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
    }
};
// @lc code=end

