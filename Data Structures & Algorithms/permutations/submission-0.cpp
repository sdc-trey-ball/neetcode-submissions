class Solution {
public:
    vector<vector<int>> perms;
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, {}, {});
        return perms;
    }

    void dfs(const vector<int>& input, set<int> visited, vector<int> cur) {
        //base case
        if(cur.size() == input.size()) {
            perms.push_back(cur);
            return;
        }

        for(int i {0}; i < input.size(); ++i) {
            if(visited.contains(i)) continue;
            cur.push_back(input.at(i));
            visited.insert(i);
            dfs(input, visited, cur);
            cur.pop_back();
            visited.erase(i);
        }
    }
};
