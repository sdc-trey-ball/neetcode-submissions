class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        map<int, pair<int, int>> cache{};
        int max_found_lis = 1;
        for(int i = nums.size() - 1; i >= 0; --i) { 
            int max_lis = 1;
            int cur {nums.at(i)};
            for(int j{i}; j < nums.size(); ++j) {
                    if(cache.count(j)) {
                        pair<int, int> val {cache[j]};
                        if(cur < val.first) {
                            max_lis = max(max_lis, 1 + val.second);
                        }
                    }
            }
            max_found_lis = max(max_lis, max_found_lis);
            cache[i] = make_pair(cur, max_lis);
        }

        return max_found_lis;
    }
};
