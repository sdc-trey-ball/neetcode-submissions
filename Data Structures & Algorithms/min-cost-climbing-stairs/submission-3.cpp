class Solution {
public:
    int min_cost = numeric_limits<int>::max();
    map<int, int> memo;
    // top down
    int minCostClimbingStairs(vector<int>& cost) {
        dfs(cost, 0, 0);
        dfs(cost, 1, 0);
        return min_cost;
    }

    void dfs(const vector<int>& cost, int i, int accumulated) {
        if(i >= cost.size()) {
            min_cost = min(min_cost, accumulated);
            return;
        }
        accumulated += cost.at(i);
        if(memo.count(i) && memo[i] < accumulated) return;
        else memo[i] = accumulated;
        dfs(cost, i + 1, accumulated);
        dfs(cost, i + 2, accumulated);
    }
};
