/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // * Recursive
        int root = 0;
        return build(preorder, inorder, root, 0,preorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& root, int left, int right) {
        if (left > right) return NULL;
        int parent = left;
        while (inorder[parent] != preorder[root]) parent++;

        root++;
        TreeNode* node = new TreeNode(inorder[parent]);
        node->left = build(preorder, inorder, root, left, parent - 1);
        node->right = build(preorder, inorder, root, parent + 1, right);
        return node;
    }
};
// @lc code=end

