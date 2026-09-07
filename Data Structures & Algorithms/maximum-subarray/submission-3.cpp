class Solution {
public:
    // two pointer
    int maxSubArray(vector<int>& nums) {
        // move right until num > lhs subarray
        int l{0}, sum{0}, max_sum = numeric_limits<int>::min();
        for(int r {0}; r < nums.size(); ++r) {
            if(sum < 0) {
                l = r;
                sum = 0;
            }
            sum += nums.at(r);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};
