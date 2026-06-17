class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
       vector<int> res {0,0,0};
       for(const auto& v: triplets) {
            int i{0};
            for(; i < 3; ++i) {
                if(v.at(i) > target.at(i)) break;
            }
            if(i!=3) continue;
            res = {max(res.at(0), v.at(0)), max(res.at(1), v.at(1)), max(res.at(2), v.at(2))};
       } 
       return res == target;
    }
};
