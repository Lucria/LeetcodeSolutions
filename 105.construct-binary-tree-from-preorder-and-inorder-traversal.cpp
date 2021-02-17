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
        // ! Iterative
        if (preorder.size() == 0) return NULL;

        // Initialize hashmap with indices of values for inorder array
        unordered_map<int, int> hashmap;
        for (int i = 0; i < inorder.size(); i++) {
            hashmap[inorder[i]] = i;
        }

        // Push root node into stack
        stack<TreeNode*> s;
        int root = preorder[0];
        TreeNode* rootNode = new TreeNode(root);
        s.push(rootNode);

        for (int i = 1; i < preorder.size(); i++) {
            int nodeVal = preorder[i];
            TreeNode* node = new TreeNode(nodeVal);

            if (hashmap[nodeVal] < hashmap[s.top()->val]) {
                // Index of new node is lower than current root, therefore left of current root
                s.top()->left = node;
            } else {
                // New node is on right of current root or is current root
                TreeNode* currRoot = NULL;
                while (!s.empty() && hashmap[nodeVal] > hashmap[s.top()->val]) {
                    currRoot = s.top();
                    s.pop();
                }
                // While loop ends when the values are equal. This means we have reached the current node;
                currRoot->right = node;
            }
            s.push(node);
        }

        return rootNode;
    }

    TreeNode* buildTreeRecursive(vector<int>& preorder, vector<int>& inorder) {
        // ! Recursive
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

