class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        map<int, int> memo; 
        memo[0] = 0;
        for(int n {1}; n <= amount; ++n) {
            int m = numeric_limits<int>::max();
            for(int coin : coins) {
                int subproblem = n - coin;
                if(subproblem < 0) continue;
                if(memo.count(subproblem)) {
                    m = min(m, memo[subproblem] + 1);
                }
            }
            if(m != numeric_limits<int>::max()) memo[n] = m;
        }
        return memo.count(amount) ? memo[amount] : -1;
    }
};
