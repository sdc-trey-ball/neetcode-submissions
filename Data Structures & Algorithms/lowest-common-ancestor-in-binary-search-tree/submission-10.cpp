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
    TreeNode* min_parent;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        min_parent = root;
        if (q->val < p->val) {
            TreeNode* temp = q;
            q = p;
            p = temp;
        }  // q > p
          if (root->val > q->val) lowestCommonAncestor(root->left, p, q);
          else if(root->val < p->val) lowestCommonAncestor(root->right, p, q);
        return min_parent;
    }
};
