class TrieNode {
public:
    map<char, TrieNode*> childs;
    bool eow;
    TrieNode() : eow{false}, childs{} {}
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = build_tree(wordDict);
        vector<bool> segs(s.length() + 1, false);
        segs[s.length()] = true;
        for(int i=s.length() - 1; i >= 0; --i) {
            TrieNode* cur = root;
            int j = i;
            while(j < s.length()) {
                cout << "\ni:" << i << " j:" << j;
                char c = s.at(j);
                if(!cur->childs.count(c)) break; 
                cur = cur->childs[c];
                if(cur->eow){ 
                    cout << "found: segs[i] = " << segs[i] << " segs[i+ (j-i) + 1] = " << segs[i + (j-i) + 1] << "\n";
                    segs[i] = segs[i + (j-i) + 1];
                    if(segs[i]) break;
                }
                j++;
            }
        }
        return segs[0];
    }

    TrieNode* build_tree(const vector<string>& word_dict) {
        TrieNode * root = new TrieNode();
        for(string s : word_dict) {
            TrieNode* cur = root;
            for(char c : s) {
                TrieNode* n;
                if(!cur->childs.count(c)) {
                    cur->childs[c] = new TrieNode();
                } 
                n = cur->childs[c];
                cur = n;
            }
            cur->eow = true;
        }
        return root;
    }
};