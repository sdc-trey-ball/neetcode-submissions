class TrieNode {
public:
    bool eow;
    unordered_map<char, TrieNode*> children;
    TrieNode() : eow{false}, children{} {}
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary(): root{new TrieNode()} {
        
    }
    
    void addWord(string word) {
        TrieNode* cur = this->root;
        for(const char c : word) {
            if(!cur->children.contains(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->eow = true;
    }
    
    bool search(string word) {
        return searched(word, this->root);
    }
    bool searched(string word, TrieNode* cur) {
        if(cur == nullptr) return false;
        for(int i{0}; i < word.length(); ++i) {
            char c = word.at(i);
            if(c == '.') {
                for(auto& e : cur->children) {
                    if(searched(word.substr(i+1), e.second)) return true;
                }
                return false;
            }
            else if(!cur->children.contains(c)) return false;
            else cur = cur->children[c];
        }
        return cur->eow;
    }
};
