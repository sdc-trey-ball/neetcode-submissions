class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int longest_streak{1}, cur{1};
        sort(nums.begin(), nums.end());
        for(int i{0}; i < nums.size() - 1; ++i) {
            if(nums.at(i+1) - nums.at(i) == 1) {
                cur++;
                longest_streak = max(longest_streak, cur); 
            } 
            else if(nums.at(i+1) - nums.at(i) == 0) { //ignore duplicates
                continue;   
            } else {
                cur = 1;
            }
        }
        return longest_streak;
    }
};
