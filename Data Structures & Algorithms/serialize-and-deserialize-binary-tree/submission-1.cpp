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

class Codec {
   public:
    // dfs practice
    //  Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "n,";
        return to_string(root->val) + "," + serialize(root->left)  + serialize(root->right);
    }
    TreeNode* ds(stringstream& ss) {
        if (ss.peek() == 'n') { ss.ignore(2); return nullptr;}
        int n{};
        ss >> n;
        TreeNode* root = new TreeNode(n);
        ss.ignore(1);
        root->left = ds(ss);
        root->right = ds(ss);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.at(0) == 'n') return nullptr;
        stringstream ss{data};
        return ds(ss);
    }
};
