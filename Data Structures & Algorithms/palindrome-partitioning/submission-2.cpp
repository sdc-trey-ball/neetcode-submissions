class Solution {
public:
    vector<vector<string>> partitions;
    unordered_map<int, vector<string>> palindrome_map;  
    vector<vector<string>> partition(string s) {
        // Build plaindrome map - All length > 1 palindromes
        for(int i{0}; i < s.length(); ++i) {
            for(int j{i + 1}; j < s.length(); j++) {
                if(is_palindrome({s.begin() + i, s.begin() + j+1})) { 
                    palindrome_map[i].push_back({s.begin() + i, s.begin() + j+1});
                }
            }
        }
        
        dfs(s, {}, 0);
        return partitions;
    }

    bool is_palindrome(string s) {
        for(int i{0}; i < s.length() / 2; ++i) {
            if(s.at(i) != s.at(s.length() - 1 - i)) return false;
        }
        return true;
    }

    void dfs(const string& s, vector<string> cur, int cur_index) {
        // Base Case
        if(cur_index == s.length()){
            partitions.push_back(cur); 
            return; 
        }
        for(const auto& st : palindrome_map[cur_index]) {
            cur.push_back(st);
            dfs(s, cur, cur_index + st.length());
            cur.pop_back();
        }
        cur.push_back({s.at(cur_index)});
        dfs(s, cur, cur_index + 1);
    }
};
