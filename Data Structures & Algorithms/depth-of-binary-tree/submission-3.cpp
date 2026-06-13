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
    int maxDepth(TreeNode* root) {
       stack<pair<TreeNode*, int>> traversal_stack{};
       traversal_stack.push({root, 1});
       int max {0};
       while(!traversal_stack.empty()) {
            auto top = traversal_stack.top();
            traversal_stack.pop();
            if(!top.first) continue;
            max = std::max(max, top.second);
            traversal_stack.push({top.first->right, top.second +1}); 
            traversal_stack.push({top.first->left, top.second +1}); 
       }
       return max;
    }
};
