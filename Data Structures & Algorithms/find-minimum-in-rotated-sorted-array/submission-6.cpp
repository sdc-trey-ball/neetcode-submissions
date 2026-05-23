class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size() == 1) return nums.at(0);
        int low {0}, high=nums.size() - 1;
        int mini = numeric_limits<int>::max();
        while(low <= high) {
            int m = (high + low) / 2;
            int m_val = nums.at(m);
            if(nums.at(high) > nums.at(low)) return nums.at(low) < mini ? nums.at(low) : mini;
            mini = min(mini, m_val);
            if(nums.at(m) >= nums.at(low)) {
               low = m +1; 
            } else {
               high = m -1; 
            }
        }  
         return mini;
    }
};
