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
    vector<int> rightSideView(TreeNode* root) {
        // declare vector
        // bfs of pair node, int
        vector<int> right_nodes{};
        queue<pair<TreeNode*, int>> bfs{}; 
        bfs.push({root, 0});
        // while not empty
        while(!bfs.empty()) {
            pair<TreeNode*, int> cur = bfs.front();
            bfs.pop();
            if(!cur.first) continue;
            if(right_nodes.size() <= cur.second) right_nodes.push_back(cur.first->val);
            bfs.push({cur.first->right, cur.second + 1});
            bfs.push({cur.first->left, cur.second + 1});
        }
        return right_nodes;
        
    }
};
