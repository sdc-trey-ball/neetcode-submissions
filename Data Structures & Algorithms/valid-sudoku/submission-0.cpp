class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       //row check
        map<int, int> row_map; 
       for(const vector<char>& row : board) {
            for(const char &n : row) {
                if(!isdigit(n)) continue;
                if(row_map.count(n - '0') != 0) {
                    return false;
                }
                row_map[n - '0']++;
            }
            row_map.clear();
       } 
       for(int col {0}; col < 9; col++) {
            for(int row{0}; row < 9; row++) {
                int n = board.at(row).at(col);
                if(!isdigit(n))continue;
                if(row_map.count(n - '0') != 0) {
                    return false;
                }
                row_map[n - '0']++;
            }
            row_map.clear();
       } 

       // in da 6 
        for(int down = 0; down < 9; down += 3){ 
            for(int right=0; right < 9; right +=3) {
            for(int row {0}; row < 3; ++row) {
                for(int col{0}; col < 3; ++col) {
                    int n = board.at(down + row).at(right + col);
                    if(!isdigit(n))continue;
                    if(row_map.count(n - '0') != 0) {
                        return false;
                    }
                    row_map[n - '0']++;
                }
            }
            row_map.clear();
            }
        }

    return true;
    }
};
