class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        map<int, int> freq_map;
        for (const auto& n: nums) {
            freq_map[n]++;
        }
        vector<vector<int>> bucket(size) ;
        for(const auto& freq_pair : freq_map) {
            bucket[freq_pair.second-1].push_back(freq_pair.first);
        }
        vector<int> ans{};
        int found{0};
        for(int i{size - 1}; i >= 0; --i) {
           for(const auto& n: bucket[i]) {
                ans.push_back(n);
                found++;
                if(found == k) return ans;
           }
        }
        return ans;
    }
};
