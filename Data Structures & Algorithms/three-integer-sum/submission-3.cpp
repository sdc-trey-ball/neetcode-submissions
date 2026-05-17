class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sorted
        sort(nums.begin(), nums.end());
        //for each num find pair with two pointer    
        unordered_set<int> found{};
        int l{0}, r{static_cast<int>(nums.size()) - 1};
        int n{0}, right{0}, left{0};
        vector<vector<int>> to_ret;
        for(int i {0}; i < static_cast<int>(nums.size()); ++i) {
            n = nums.at(i);
            l = i+ 1;
            r = static_cast<int>(nums.size()) - 1;
            while(l < r) {
                left = nums.at(l);
                right = nums.at(r);
                if(l == i) {
                   l++;
                   continue; 
                } else if(r == i) {
                   r--;
                   continue; 
                }
                int sum = n + right + left;
                if(sum == 0) {
                    if (find(to_ret.begin(), to_ret.end(), vector<int>{n, right, left}) != to_ret.end()) { l++; r--; continue;}
                    to_ret.push_back({n, right, left});
                    l++;
                    r--;
                } else if (sum > 0){
                    r--;
                } else {
                    l++;
                }
            }
        }
        return to_ret;
        // add to collection
        // always check if contained in
    }
};
