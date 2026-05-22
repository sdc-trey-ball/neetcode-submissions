class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high{static_cast<int>(nums.size()) - 1}, low{0};
        while(low <= high) {
            int m = low + ((high - low) / 2);
            int middle = nums.at(m);
            if(middle > target)high = m - 1;
            else if(middle < target) low = m + 1;
            else return m;
        }
        return -1;
    }
};
