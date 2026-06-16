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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels {};
        queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, 0});
        while(!bfs.empty()) {
            pair<TreeNode*, int> cur = bfs.front();
            bfs.pop();
            if(!cur.first) continue;
            if(levels.size() <= cur.second) levels.push_back(vector<int>());
            levels.at(cur.second).push_back(cur.first->val);
            bfs.push({cur.first->left, cur.second +1});
            bfs.push({cur.first->right, cur.second +1});
        }
        return levels;
    }
};
