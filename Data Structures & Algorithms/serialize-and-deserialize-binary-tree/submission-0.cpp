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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        //bfs, add val to string or n for null
        queue<TreeNode*> bfs{};
        bfs.push(root);
        string s{};
        stringstream ss{s};
        while(!bfs.empty()) {
            TreeNode* cur = bfs.front();
            bfs.pop();
            if(!cur) {
                ss << "n,";
                continue;
            }
            ss << cur->val<< ',';    
            bfs.push(cur->left);
            bfs.push(cur->right);
        } 
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) {
           return nullptr; 
        }
        stringstream ss{data};
        int num{};
        ss >> num;
        ss.ignore(1);
        TreeNode* root = new TreeNode(num);
        queue<TreeNode*> bfs{};
        bfs.push(root);
        while(!bfs.empty()) {
            TreeNode* cur = bfs.front();
            bfs.pop();
            if(!cur) continue;
            if(ss.peek() != 'n') {
                ss >> num;
                ss.ignore(1);
                cur->left = new TreeNode(num);
            } else {
                ss.ignore(2);
            }
            if(ss.peek() != 'n') {
                ss >> num;
                ss.ignore(1);
                cur->right = new TreeNode(num);
            } else {
                ss.ignore(2);
            }
            bfs.push(cur->left);
            bfs.push(cur->right);
        }
        return root;
    }
};
