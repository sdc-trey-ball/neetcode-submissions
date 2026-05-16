class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       // for each if n + 1 is there add to map
       // map of count so if in range increment  
        
        //init check
        if(nums.size() <= 1) return nums.size();
        // inital loop for finding 'starters'
        unordered_set<int> candidates;
        for(const auto &n : nums) {
            if(find(nums.begin(), nums.end(), n - 1) == nums.end() && find(nums.begin(), nums.end(), n + 1) != nums.end()) {
                candidates.insert(n);
            }
        }

        int max_streak{1};
        for(const auto &c : candidates) {
            int cur {1};
            while(find(nums.begin(), nums.end(), c + cur) != nums.end()) {
                cur++;
            }
            max_streak = max(max_streak, cur);
        }
       return max_streak; 
    }
};
