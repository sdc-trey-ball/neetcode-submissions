class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans (nums.size(), 1);
        int size = nums.size();
        for(int i = 0; i < size - 1 ; ++i) {
            ans.at(i +1) = ans.at(i) * nums.at(i);
        
        }
        int rev = 1;
        for(int i = 0; i < nums.size() - 1; ++i) {
            rev *= nums.at(nums.size() - 1 - i);
            ans.at(nums.size() - 2 - i) *= rev;
        }
        return ans;
    }
};
