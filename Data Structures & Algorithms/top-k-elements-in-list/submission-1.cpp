class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // unordered map of int to int
        // loop through
        // at end get begin + k         
        map<int, int> freq_map;
        for (const auto& n: nums) {
            freq_map[n]++;
        }
        vector<int> ans;
        vector<pair<int, int>> freq_pair(freq_map.begin(), freq_map.end());
        sort(freq_pair.begin(), freq_pair.end(), [](auto a, auto b) {return a.second > b.second;});
        auto rit = freq_pair.begin();
        int counter{0};
        while(counter++ < k) {
            ans.emplace_back(rit->first);
            rit++;
        }
        return ans;
    }
};
