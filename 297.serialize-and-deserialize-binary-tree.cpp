/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream stream;
        serial(root, stream);
        return stream.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream stream(data);
        return deserial(stream);
    }

private:
    void serial(TreeNode* root, ostringstream& stream) {
        if (root) {
            stream << root->val << " ";
            serial(root->left, stream);
            serial(root->right, stream);
        } else {
            stream << "~ ";
        }
    }

    TreeNode* deserial(istringstream& stream) {
        string val;
        stream >> val;
        if (val == "~") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserial(stream);
        root->right = deserial(stream);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

