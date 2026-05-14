class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        vector<int> fwd(nums.size());
        vector<int> back(nums.size());
        fwd[0] = 1; 
        back[nums.size() - 1] = 1;
        for(int i{i}; i < nums.size() - 1; ++i) {
            fwd[i + 1] = fwd[i] * nums.at(i);
            back[nums.size() - 2 - i] = back[nums.size() - 1 - i] * nums.at(nums.size() - 1 - i);
        }
        for(int i = 0; i < nums.size(); ++i)
            ans.push_back(fwd[i] * back[i]);
        return ans; 
    }

};
