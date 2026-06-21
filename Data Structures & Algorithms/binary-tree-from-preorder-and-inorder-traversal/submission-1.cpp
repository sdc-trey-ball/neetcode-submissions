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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       if(!preorder.size() || !inorder.size()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int mid = distance(inorder.begin(), find(inorder.begin(), inorder.end(), preorder.at(0)));  
        vector<int> leftPre(preorder.begin() + 1,
                    preorder.begin() + mid + 1);
        vector<int> leftIn(inorder.begin(),
                   inorder.begin() + mid);

        root->left = buildTree(leftPre, leftIn);

        vector<int> rightPre(preorder.begin() + mid + 1,
                     preorder.end());
        vector<int> rightIn(inorder.begin() + mid + 1,
                    inorder.end());

        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};
