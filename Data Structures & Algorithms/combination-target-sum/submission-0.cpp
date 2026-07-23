class Solution {
public:
    vector<vector<int>> matched_set;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        search(nums, target, {}, 0, 0);
        return matched_set;
    }

    void search(const vector<int>& nums, const int target, vector<int> cur,
        int cur_total, int start) {
        // base case 
        if(cur_total > target) return;
        if(cur_total == target) {
            matched_set.push_back(cur);
            return;
        }
        for(int n{start}; n < nums.size(); ++n) {
            int i = nums.at(n);
            cur.push_back(i);
            search(nums, target, cur, cur_total + i, n);
            cur.pop_back();
        }
    }
};
