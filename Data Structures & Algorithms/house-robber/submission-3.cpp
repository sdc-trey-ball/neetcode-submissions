class Solution {
public:
    // top down
    int rob(vector<int>& nums) {
        dfs(nums, 0, {0, 0});
        pair<int, int> ans = memo[nums.size() - 1] ;
        return max(ans.first, ans.second);
    }

    map<int, pair<int, int>> memo;
    void dfs(const vector<int>& nums, int i, pair<int,int> build) {
        if(i >= nums.size()) return;
        if(memo.count(i)) {
            return;
        }
        memo[i] = {build.second + nums.at(i), max(build.first, build.second)};
        dfs(nums, i + 1, memo[i]);
    }
};
