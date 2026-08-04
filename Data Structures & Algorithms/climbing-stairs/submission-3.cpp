class Solution {
public:
    // O(n) + 0(3)
    int climbStairs(int n) {
        int lead = 1;
        int back = 1;
        for(int i = 2; i<= n; ++i) {
            int val = lead + back;
            back = lead;
            lead = val;
        }
        return lead;
    }
};
