class Solution {
public:
    // bottom up 
    int maxProduct(vector<int>& nums) {
        int cur_max{1}, cur_min{1}, max_prod = numeric_limits<int>::min();
        for(int i {0}; i < nums.size(); ++i) {
            int cur {nums.at(i)};
            int c_max {cur_max * cur};
            int c_min {cur_min * cur};
            cur_min = min(min(c_min, c_max), cur); 
            cur_max = max(max(c_min, c_max), cur); 
            max_prod = max(cur_max, max_prod);
        }
        return max_prod;
    }
};
