class Solution {
public:
    // bottom up
    int rob(vector<int>& nums) {
        if(nums.size() <= 2) {
            if(nums.size() == 1) return nums.at(0);
            return max(nums.at(0), nums.at(1));
        }
        map<int, pair<int, int>> memo;
        memo[-1] = make_pair(0,0);
        for(int i = 0; i < nums.size(); ++i) {
            pair<int,int> prev = memo[i-1];
            int robbed = prev.second + nums.at(i);
            int unrobbed = max(prev.first, prev.second);
            memo[i] = make_pair(robbed, unrobbed);
        }
        return max(memo[nums.size() - 1].first, memo[nums.size() - 1].second);
        
    }
};
