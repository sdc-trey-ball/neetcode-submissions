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
    int max_sum {-1000};
    int maxPathSum(TreeNode* root) {
        find_max(root);
        return max_sum;
    }
    int find_max(TreeNode* root) {
        if(!root) return 0;
        int l = find_max(root->left);
        int r = find_max(root->right);
        if(l < 0) l = 0;
        if(r < 0) r = 0;
        int total = l + r + root->val;
        cout << root->val << ' ' << total << '\n';
        max_sum = max(max_sum, total);
        return max(l, r) + root->val;
    }
};
