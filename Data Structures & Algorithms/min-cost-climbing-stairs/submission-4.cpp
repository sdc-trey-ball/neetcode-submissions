class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        map<int, int> memo;
        int back = cost.at(0), lead = cost.at(1);
        for(int i {2}; i <= cost.size(); ++i) {
            int total = min(lead, back);
            back = lead;
            lead = total + (i < cost.size() ? cost.at(i) : 0);
        } 
        return lead;
    }
};
