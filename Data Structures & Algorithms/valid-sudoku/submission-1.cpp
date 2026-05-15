class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {   
        
        map<int, unordered_set<int>> rows{}, cols{};
        map<pair<int, int>, unordered_set<int>> square {};
        int n;
        for(int row {0}; row < 9; ++row) {
            for(int col{0}; col < 9; ++col) {
                if(!isdigit(board.at(row).at(col))) continue;   
                n = board.at(row).at(col) - '0';
                if(rows[row].count(n) || cols[col].count(n)|| square[{row/3, col/3}].count(n)) {
                    return false;
                } 
                rows.at(row).insert(n);
                cols.at(col).insert(n);
                square.at({row / 3, col / 3}).insert(n);
            }
        }  
        return true;
    }
};
