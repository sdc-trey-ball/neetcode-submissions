class Solution {
public:
    int rob(vector<int>& nums) {
        int bt = 0, bo = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int m = max(bo, bt + nums.at(i));
            bt = bo;
            bo = m;
        }
        return bo;
    }
};
