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
    int kthSmallest(TreeNode* root, int k) {
       if(!root) return -1; 
       int left = kthSmallest(root->left, k);
       stack<TreeNode*> dfs{};  
       unordered_set<TreeNode*> seen{};
       dfs.push(root);
       while(!dfs.empty()) {
            TreeNode* cur = dfs.top();
            dfs.pop();
            if(!cur)continue;
            if(seen.contains(cur)){
                k--;
                if(!k) return cur->val;
            } else { 
                dfs.push(cur->right); 
                dfs.push(cur);
                dfs.push(cur->left);
                seen.insert(cur);
            }
       }
       return -1;
    }
};
