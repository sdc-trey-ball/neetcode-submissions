class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i{0}; i < board.size(); ++i) {
            for(int j{0}; j < board.at(0).size(); ++j) {
                //if(board.at(i).at((j)) != word.front()) continue;
                if(search(board, word, {{i,j}}, {{i, j}})) return true;
            }
        }
        return false;
    }

    bool search(const vector<vector<char>>& board, const string word,
        set<pair<int,int>> searched, vector<pair<int, int>> cur) {
        
        char c = board.at(cur.back().first).at(cur.back().second);
        if(cur.size() == word.length() &&  c == word.back()) return true;
        if(c == word.at(cur.size() - 1)) {
            searched.insert({cur.back().first,cur.back().second});
            pair<int, int> p = cur.back();
            int i = p.first, j = p.second;
            // left
            if(p.second > 0 && !searched.contains({i, j - 1})) {
                cur.push_back({i, j - 1});
                if(search(board, word, searched, cur)) return true;
                cur.pop_back();
            }
            // up 
            if(p.first > 0 && !searched.contains({i - 1, j})) {
                cur.push_back({i - 1, j});
                if(search(board, word, searched, cur)) return true;
                cur.pop_back();
            }
            // right
            if(p.second < board.at(0).size() - 1 && !searched.contains({i, j + 1})) {
                cur.push_back({i, j + 1});
                if(search(board, word, searched, cur)) return true;
                cur.pop_back();
            }
            // down
            if(p.first < board.size() - 1 && !searched.contains({i + 1, j})) {
                cur.push_back({i + 1, j});
                if(search(board, word, searched, cur)) return true;
                cur.pop_back();
            }
        }     
            return false;
    }
    
};
