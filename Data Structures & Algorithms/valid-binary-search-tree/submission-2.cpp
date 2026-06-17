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
    bool isValidBST(TreeNode* root) {
       return traverse(root, numeric_limits<int>::max(), numeric_limits<int>::min()); 
    }
    bool traverse(TreeNode* cur, int min_left, int max_right) {
        if(!cur) return true;
        cout << cur->val << " min: " << min_left << " max: " << max_right <<'\n';
        if(cur->val >= min_left || cur->val <= max_right) return false;
        bool left = traverse(cur->left, cur->val, max_right); 
        bool right = traverse(cur->right, min_left, cur->val);
        return left&&right;
    }
};