class Solution {
public:
    vector<vector<int>> answer_sets;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, {}, 0, 0);
        return answer_sets;
    }
    
    void dfs(const vector<int>& candidates, const int target, vector<int> cur,
        int cur_sum, int cur_index) {
        if(cur_sum == target) {
            answer_sets.push_back(cur);
            return;
        }
        if(cur_sum > target || cur_index >= candidates.size()) {
            return;
        }
        int find_next = cur_index;
        while(find_next < candidates.size() && candidates.at(find_next) == candidates.at(cur_index)) find_next++;
        int moving = cur_index;
            cur.push_back(candidates.at(moving));
            dfs(candidates, target, cur, cur_sum + candidates.at(moving), moving + 1);
            cur.pop_back();
            dfs(candidates, target, cur, cur_sum, find_next);
        //dfs(candidates, target, cur, cur_sum, cur_index);

    }
};
