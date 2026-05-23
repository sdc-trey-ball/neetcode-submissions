class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int low {0}, high = matrix.size() * matrix.at(0).size() - 1; 
       while(low <= high) {
            int m = low + (high - low) / 2;
            int mid_val = matrix.at(m/matrix.at(0).size()).at(m%matrix.at(0).size());
            if(mid_val < target) low = m +1;
            else if(mid_val > target) high = m - 1;
            else return true;
       }
       return false;
    }
};
