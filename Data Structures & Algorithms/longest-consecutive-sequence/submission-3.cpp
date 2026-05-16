class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //init check
        if(nums.size() <= 1) return nums.size();
        // inital loop for finding 'starters'
        unordered_set<int> st {nums.begin(), nums.end()};
        int max_streak{1}, str{1};
        for(const auto &n : nums) {
            if(st.count(n - 1) == 0) {
                while(st.count(n+str) != 0) {str++;};
                max_streak = max(max_streak, str);
                str = 1;
            }
        }
        return max_streak;
    
    }
};
