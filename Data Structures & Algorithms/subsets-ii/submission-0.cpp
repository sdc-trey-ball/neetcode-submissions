class Solution {
public:
    vector<vector<int>> subsets;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        subset(nums, {}, 0);
        return subsets;
    }
    void subset(const vector<int>& nums, vector<int> cur, int i) {
        if(i == nums.size()) {
            subsets.push_back(cur);
            return;
        }
        cur.push_back(nums.at(i));
        subset(nums, cur, i+1);
        while(i < nums.size() && nums.at(i) == cur.back()) i++;
        cur.pop_back();
        subset(nums, cur, i);

    }
};