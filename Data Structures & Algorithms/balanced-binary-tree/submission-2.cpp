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
    bool to_ret{true};
    bool isBalanced(TreeNode* root) {
       to_ret = true;
       helper(root); 
       return to_ret;
    }
    
    int helper(TreeNode* n) {
        if(!n) return 0;
        int left = helper(n->left);
        int right = helper(n->right);
        if(abs(left - right) > 1) to_ret = false;
        return max(left, right) + 1;
    }
};
