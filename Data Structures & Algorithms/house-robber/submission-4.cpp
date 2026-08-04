class Solution {
public:
    // bottom up, O(1) mem
    int rob(vector<int>& nums) {
        if(nums.size() <= 2) {
            if(nums.size() == 1) return nums.at(0);
            return max(nums.at(0), nums.at(1));
        }
        pair<int, int> prev = {0,0};
        for(int i = 0; i < nums.size(); ++i) {
            int robbed = prev.second + nums.at(i);
            int unrobbed = max(prev.first, prev.second);
            prev = make_pair(robbed, unrobbed);
        }
        return max(prev.first, prev.second);
    }
};