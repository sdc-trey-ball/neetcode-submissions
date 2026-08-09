class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 1) return nums.empty() ? 0 : nums.at(0);
        pair<int, int> index_zero {0,0};
        pair<int, int> index_one {0,0};

        for(int i = 0; i < nums.size() - 1; ++i) {
            int j = i + 1;
            int robbed_zero = nums.at(i) + index_zero.second;
            int robbed_one = nums.at(j) + index_one.second;
            int unrobbed_zero = max(index_zero.first, index_zero.second);
            int unrobbed_one = max(index_one.first, index_one.second);
            index_zero = {robbed_zero, unrobbed_zero};
            index_one = {robbed_one, unrobbed_one};
        }
        return max(max(index_zero.first, index_zero.second), max(index_one.first, index_one.second));
    }
};
