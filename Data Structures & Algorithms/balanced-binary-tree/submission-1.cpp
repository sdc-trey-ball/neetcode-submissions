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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool found {true}; 
        depth(root, 1, found); 
        return found;
    }
    int depth(TreeNode* n, int dp, bool& found) {
        if(!n) return dp;
        int l_depth = n->left ? depth(n->left, dp + 1, found) : dp;
        int r_depth = n->right ? depth(n->right, dp + 1, found) : dp;
        cout << n->val << ' ' << r_depth << ' ' << l_depth << '\n';
        if(abs(l_depth - r_depth) > 1)found = false;
        return l_depth > r_depth ? l_depth : r_depth;
    }
};
