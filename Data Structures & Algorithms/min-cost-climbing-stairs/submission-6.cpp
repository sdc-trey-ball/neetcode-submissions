class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        for(int i {2}; i < cost.size(); ++i) {
            int total = min(cost.at(i - 1), cost.at(i - 2));
            cost.at(i) += total;
        } 
        return cost.at(cost.size() - 1);
    }
};
