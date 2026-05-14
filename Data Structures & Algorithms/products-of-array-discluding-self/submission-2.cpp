class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans (nums.size(), 1);
        int size = nums.size();
        for(int i = 0; i < size - 1 ; ++i) {
            ans.at(i +1) = ans.at(i) * nums.at(i);
        
        }
        int rev = 1;
        for(int i = size - 1; i > 0; --i) {
            rev *= nums.at(i);
            ans.at(i - 1) *= rev;
        }
        return ans;
    }
};
