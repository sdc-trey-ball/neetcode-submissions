class Solution {
public:
    // top down
    int rob(vector<int>& nums) {
        dfs(nums, 0, {0, 0});
        pair<int, int> ans = memo[nums.size() - 1] ;
        return max(ans.first, ans.second);
    }

    map<int, pair<int, int>> memo;
    pair<int, int> dfs(const vector<int>& nums, int i, pair<int,int> build) {
        if(i >= nums.size()) return {0,0};
        if(memo.count(i)) {
            return memo.at(i);
        }
        memo[i] = {build.second + nums.at(i), max(build.first, build.second)};
        return dfs(nums, i + 1, memo[i]);
    }
};
