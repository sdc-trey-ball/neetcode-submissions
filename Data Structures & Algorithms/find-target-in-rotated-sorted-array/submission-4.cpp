class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low {0}, high = nums.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            cout << nums.at(mid) << ' ';
            if(nums.at(mid) == target) return mid;
            if(nums.at(high) == target) return high;
            if(nums.at(low) == target) return low;
            if(target < nums.at(mid)){
                if(nums.at(low) < nums.at(mid) && nums.at(low) <= target){ // in order
                    high = mid - 1;
                } else {
                if(nums.at(low) > nums.at(mid)) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
                }
            } else {
                if(nums.at(mid) < nums.at(high) && nums.at(high) >= target){ // in order
                    low = mid + 1;
                } else {
                if(target >nums.at(mid)) {
                    low = mid + 1;
                } else {
                    low = mid + 1;
                }
                }
            }
        }
        return -1;
    }
};
