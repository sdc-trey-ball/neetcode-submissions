class Solution {
public:
    map<char, vector<char>> letter_map{
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };
    vector<string> combinations;
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
       dfs(digits, "", 0);
       return combinations;
    }

    void dfs(const string& digits, string cur, int cur_index) {
        // Base Case
        if(cur_index == digits.length()) {
            combinations.push_back(cur);
            return;
        }
        //int d = digits.at(cur_index) + '0';
        //vector<char> cur_map = letter_map.at(d);
        // Choices  
        for(const char& c : letter_map.at(digits.at(cur_index))){//cur_map){
            cur.push_back(c);
            dfs(digits, cur, cur_index + 1);
            cur.pop_back();
        }
    }
};
