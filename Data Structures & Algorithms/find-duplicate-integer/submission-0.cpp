class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       // naive O(n^2) solution
       for(int i = 0; i < nums.size(); ++i) {
            for(int j{0}; j <nums.size(); ++j) {
                if(i==j) continue;
                if(nums[i] == nums[j]) return nums[i];
            }
       }
       return -1;
    }
};
