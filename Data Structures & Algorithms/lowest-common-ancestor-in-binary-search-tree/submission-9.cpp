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
        if (root->val >= q->val || (p->val <= root->val && root->val <= q->val) || root->val < p->val) {
          cout << "Helper: " << root->val << "\n";
            if (root->val > q->val) lowestCommonAncestor(root->left, p, q);
            else if(root->val < p->val) lowestCommonAncestor(root->right, p, q);
        }
        return min_parent;
    }
    void helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        cout << "Helper: " << root->val << "\n";
        if (!root) return;
        if (root->val >= q->val || (p->val <= root->val && root->val <= q->val)) {
            min_parent =  min_parent->val < root->val ? min_parent : root;
            if (root->val > q->val) helper(root->left, p, q);
        }
    }
};
