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
    int ans {-1};
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return ans;
    }
    int traverse(TreeNode* root, int k) {
        if(!root) return 0; 
        int left = traverse(root->left, k);
        if(k - left == 1) ans = root->val;
        int right = traverse(root->right, k - left - 1);
        cout << root->val << " " << left << " " << right << '\n';
        return (left + right + 1);
    }
};
