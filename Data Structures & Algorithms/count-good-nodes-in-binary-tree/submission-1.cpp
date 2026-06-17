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
    int goodNodes(TreeNode* root) {
        return traverse(root, root->val);
    }
    int traverse(TreeNode* n, int prev_max) {
        if(!n) return 0;
        prev_max = max(prev_max, n->val);
        int l_found = traverse(n->left, prev_max);
        int r_found = traverse(n->right, prev_max);
        return l_found + r_found + (prev_max == n->val ? 1 : 0);
    }
};
