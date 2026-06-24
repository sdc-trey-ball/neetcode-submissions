class PrefixTree {
public:
    char val;
    unordered_map<char, PrefixTree*> chars;
    PrefixTree():chars{}, val{} {
    }
    PrefixTree(char c):chars{}, val{c} {
    }
    
    void insert(string word) {
        PrefixTree* cur = this;
        for(int i = 0; i < word.length(); ++i) {
            char c = word.at(i);
            cout << c <<' ';
            if(!cur->chars.contains(c)){
               cur->chars.emplace(c,new PrefixTree(c)); 
            }
            cur = cur->chars[c];
        }
        cur->chars.emplace('*', nullptr);
    }
    
    bool search(string word) {
        if(word.size() == 0) return true;
        PrefixTree* cur = this;
        for(int i = 0; i < word.length(); ++i) {
            char c = word.at(i);
            if(!cur->chars.contains(c)){
                return false;
            }
            cur = cur->chars[c];
        }
        return cur->chars.count('*') != 0;
    }
    
    bool startsWith(string prefix) {
        if(prefix.size() == 0) return true;
        PrefixTree* cur = this;
        for(int i = 0; i < prefix.length(); ++i) {
            char c = prefix.at(i);
            if(!cur->chars.contains(c)){
                return false;
            }
            cur = cur->chars[c];
        }
        return true;
    }
};
