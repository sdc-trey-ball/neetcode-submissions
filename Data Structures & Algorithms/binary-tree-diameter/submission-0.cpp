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
    int diameterOfBinaryTree(TreeNode* root) {
        int x = 0;
        diam(root, x);
        return x;
    }
    int diam(TreeNode* root, int& max_val) {
        if(!root) return 0;
        int l_path = diam(root->left, max_val);
        int r_path = diam(root->right, max_val);
        max_val = std::max(max_val, l_path + r_path);
        return 1 + std::max(l_path, r_path);
    }
};
