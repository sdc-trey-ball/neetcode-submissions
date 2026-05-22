class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low {0}, high = matrix.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            vector<int> value = matrix.at(mid);
            if(count(value.begin(), value.end(),(target))) return true;
            else if(target > value.at(value.size() - 1)) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};
