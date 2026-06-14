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
    int x {0};
    int diameterOfBinaryTree(TreeNode* root) {
        x = 0;
        diam(root);
        return x;
    }
    int diam(TreeNode* root) {
        if(!root) return 0;
        int l_path = diam(root->left);
        int r_path = diam(root->right);
        x = std::max(x, l_path + r_path);
        return 1 + std::max(l_path, r_path);
    }
};
