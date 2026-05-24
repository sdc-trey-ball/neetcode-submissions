class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low {0}, high = nums.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            cout << nums.at(mid) << ' ';
            if(nums.at(mid) == target) return mid;
            if(target < nums.at(mid)) {
                 if(nums.at(low) <= nums.at(mid)) {
                    if(target >= nums.at(low)) high = mid - 1;
                    else low = mid + 1;
                 } else {
                    high = mid - 1;
                 }
            } else {
                if(nums.at(mid) <= nums.at(high)){
                    if(target <= nums.at(high)) low = mid +1;
                    else high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};
