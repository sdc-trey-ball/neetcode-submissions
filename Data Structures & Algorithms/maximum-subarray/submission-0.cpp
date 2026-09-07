class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = numeric_limits<int>::min(), cur_sum{};

        for(int i {0}; i < nums.size(); ++i) {
            int cur_max {cur_sum + nums.at(i)};
            cur_sum = max(cur_max, nums.at(i));
            max_sum = max(max_sum, cur_sum);
        }
        
        return max_sum;
    }
};
