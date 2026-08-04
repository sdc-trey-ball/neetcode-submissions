class Solution {
public:
    int climbStairs(int n) {
       return dfs(n, 0);
    }
    
    map<int, int> memo;
    int dfs(int n, int i) {
        if(i >= n) return i == n ? 1 : 0;
        if(memo.count(i)) return memo[i];
        int ans =  dfs(n, i + 1) + dfs(n, i + 2);
        memo[i] = ans;
        return ans;
    }

};