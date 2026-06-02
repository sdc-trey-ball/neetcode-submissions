class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // for loop on numbers possible
        //if findFirst and findLast dont equal return
        vector<int>::iterator st = nums.begin(), end = nums.end() - 1;
        for(int cur{1}; cur < nums.size(); cur++) {
            auto first = find(nums.begin(), nums.end(), cur);
            auto last = find(nums.rbegin(), nums.rend(), cur);
            auto last_flip = prev(last.base());
            if(first == nums.end()) continue;
            if(distance(nums.begin(), first) != distance(nums.begin(), last_flip)) return cur;
        }
        return -1; 
    }
};
