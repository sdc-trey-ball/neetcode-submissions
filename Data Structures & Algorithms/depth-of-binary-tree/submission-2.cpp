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
       queue<pair<TreeNode*, int>> to_traverse{};
       to_traverse.push({root, 1});
       int max{0};
       while(!to_traverse.empty()) {
            auto to_check = to_traverse.front();
            to_traverse.pop();
            if(!to_check.first) continue;
            max = std::max(max, to_check.second);
            to_traverse.push({to_check.first->right, to_check.second+1});
            to_traverse.push({to_check.first->left, to_check.second+1});
       }
       return max;
    }
};
