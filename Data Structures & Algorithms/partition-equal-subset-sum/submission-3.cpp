class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int partition_sum {sum / 2};
        int found {0};
        return dfs(nums, partition_sum, 0, 0);
    }

    bool dfs(const vector<int>& nums, const int target_sum, int i, int sum) {
        if(sum > target_sum || i == nums.size()) return false;
        if(sum == target_sum) return true;
        // iterate
        int cur = nums.at(i);
        return dfs(nums, target_sum, i + 1, sum + cur) || dfs(nums, target_sum, i + 1, sum);
    }
};
