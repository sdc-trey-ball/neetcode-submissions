class Solution {
public:
    // two pointer
    int maxSubArray(vector<int>& nums) {
        // move right until num > lhs subarray
        int l{0}, sum{0}, max_sum = numeric_limits<int>::min();
        for(int r {0}; r < nums.size(); ++r) {
            while(r < nums.size() && sum > 0) {
                //cout << "l: " << l << " r: " << r << "\n";
                int r_val {nums.at(r)};
                sum += r_val;
                max_sum = max(max_sum, sum);
                r++;
            }
            if(r < nums.size()) {
                l = r; 
                sum = nums.at(r);
                max_sum = max(max_sum, sum);
            }
        }
        return max_sum;
    }
};
